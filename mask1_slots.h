//###############################################################
//# mask1_slots.h for ProcessViewServer created: dom. mai. 11 18:39:57 2025
//# please fill out these slots
//# here you find all possible events
//# Yours: Lehrig Software Engineering
//###############################################################

// todo: uncomment me if you want to use this data aquisiton
// also uncomment this classes in main.cpp and pvapp.h
// also remember to uncomment rllib in the project file
extern rlModbusClient     modbus;  //Change if applicable
//extern rlSiemensTCPClient siemensTCP;
//extern rlPPIClient        ppi;
#define BG_COLOR 0xef,0xf0,0xf1

typedef struct // (todo: define your data structure here)
{
 int val, etapa;
 float u0,i0,teta0,f0,t0;
 float u1,i1,teta1,f1,t1;
 float u2,i2,teta2,f2,t2;
 float v,vmax,vmin;
 int t, F0, d;
}
DATA;

float *valptr(DATA *d);
const char *nomeEtapa[] = {"PRÉ-FALTA", "FALTA", "PÓS-FALTA", ""};
const char *nomeVal[]   = {"TENSÃO", "CORRENTE", "ÂNGULO", "FREQUÊNCIA", "DURAÇÃO", ""};

static int slotInit(PARAM *p, DATA *d)
{
  if(p == NULL || d == NULL) return -1;
  //memset(d,0,sizeof(DATA));
  pvResize(p,0,1366,768);

  p->sleep = 100;
  int id, i;

  d->val = 0;
  d->etapa = 0;
  d->u0 = d->u1 = d->u2 = 115.0;
  d->i0 = d->i1 = d->i2 = 0;
  d->teta0 = d->teta1 = d->teta2 = 0;
  d->f0 = d->f1 = d->f2 = 60.0;
  d->t0 = 2.0;
  d->t1 = 10.0;
  d->t2 = 5.0;
  d->v  = *valptr(d);//d->u0;
  d->vmax = 450;
  d->vmin = 0;
  d->t = 0;
  d->F0 = 0;
  d->d = 0;

  id = _ETAPA_;
  for(i = 0; i<3; i++) pvInsertItem(p,id,-1,NULL,nomeEtapa[i]);  
  id = _VAL_;
  for(i = 0; i<5; i++) pvInsertItem(p,id,-1,NULL,nomeVal[i]);  

  id = _INPUT_;
  pvPrintf(p,id,"%g",d->v);

  modbus.writePresetSingleRegister(13,1120,0);
  modbus.writePresetSingleRegister(13,1156,0);
  return 0;
}

static int slotNullEvent(PARAM *p, DATA *d)
{
  if(p == NULL || d == NULL) return -1;

  int k = 1000 / p->sleep;
  d->t++;
  switch(d->F0){
      case 4 : // PRÉ FALTA
          pvPrintf(p,_START_,"STOP");
          pvSetBackgroundColor(p,_PREFALTA_,WHITE);
          d->t = 0;
          modbus.writePresetSingleRegister(13,1152,d->u0*100);
          modbus.writePresetSingleRegister(13,1154,d->f0*100);
          modbus.writePresetSingleRegister(13,1159,d->i0*1000);
          modbus.writePresetSingleRegister(13,1160,d->teta0*1000);
          modbus.writePresetSingleRegister(13,1120,1);
//          modbus.writePresetSingleRegister(13,1156,1);
          d->F0--;
          break;
      case 3 : // FALTA
          if(d->t > k*d->t0){
              pvSetBackgroundColor(p,_FALTA_,WHITE);
              d->t = 0;
              d->d = k;
              modbus.writePresetSingleRegister(13,3220,1); // Liga o cronômetro
              modbus.writePresetSingleRegister(13,1152,d->u1*100);
              modbus.writePresetSingleRegister(13,1154,d->f1*100);
              modbus.writePresetSingleRegister(13,1159,d->i1*1000);
              modbus.writePresetSingleRegister(13,1160,d->teta1*1000);
              d->F0--;
          }
          break;
      case 2 : // PÓS FALTA
          if(d->t > k*d->t1 || v.DI0 || v.DI1){
              pvSetBackgroundColor(p,_POSFALTA_,WHITE);
              d->t = 0;
              if(v.Status) modbus.writePresetSingleRegister(13,3220,1); // Desliga o cronômetro se estiver ligado
              modbus.writePresetSingleRegister(13,1152,d->u2*100);
              modbus.writePresetSingleRegister(13,1154,d->f2*100);
              modbus.writePresetSingleRegister(13,1159,d->i2*1000);
              modbus.writePresetSingleRegister(13,1160,d->teta2*1000);
              d->F0--;
              if(v.Status) pvSetBackgroundColor(p,_FALTA_,RED);
              else         pvSetBackgroundColor(p,_FALTA_,GREEN);
          }
          break;
      case 1 : // FIM
          if(d->t > k*d->t2 || d->t < 0){
              pvSetBackgroundColor(p,_PREFALTA_, BG_COLOR);
              pvSetBackgroundColor(p,_FALTA_,    BG_COLOR);
              pvSetBackgroundColor(p,_POSFALTA_, BG_COLOR);
              if(v.Status) modbus.writePresetSingleRegister(13,3220,1); // Desliga o cronômetro se estiver ligado
              modbus.writePresetSingleRegister(13,1120,0);
              modbus.writePresetSingleRegister(13,1156,0);
              d->F0--;
              pvPrintf(p,_START_,"START");
          }
          break;
  }

  return 0;
}

static int slotButtonEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  switch(id){
    case _START_ : 
        if(!d->F0){
            modbus.writePresetSingleRegister(13,1120,1);
            d->F0 = 4;
        }
        else {
            d->t = -100;
            d->F0 = 1;
        } 
        break;
    case _INPUT_ :
        float *f = valptr(d);
//        printf("\n*f = %g  d->val = %g\n", *f, d->v);
        *f = d->v;
//        printf("*f = %g  d->val = %g\n\n", *f, d->v);
        break;
  }
  return 0;
}

static int slotButtonPressedEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  switch(id){
      case _DO0_ : modbus.writePresetSingleRegister(13,3190,1); break;
      case _DO1_ : modbus.writePresetSingleRegister(13,3192,1); break;
  }
  return 0;
}

static int slotButtonReleasedEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  switch(id){
      case _DO0_ : modbus.writePresetSingleRegister(13,3191,1); break;
      case _DO1_ : modbus.writePresetSingleRegister(13,3193,1); break;
  }
  return 0;
}

static int slotTextEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  double f,f1;

  switch(id){
  case _VAL_ :
      d->val = 0;
      while(strcmp(text, nomeVal[d->val])) d->val++;
      d->v = *valptr(d);
      pvPrintf(p,_INPUT_,"%g",d->v);
      switch(d->val){
          case TENSAO     : d->vmin = 0;    d->vmax = 450; break;
          case CORRENTE   : d->vmin = 0;    d->vmax = 10;  break;
          case ANGULO     : d->vmin = -180; d->vmax = 180; break;
          case FREQUENCIA : d->vmin = 45;   d->vmax = 70;  break;
          case TEMPO      : d->vmin = 1;    d->vmax = 60;  break;
      }
      break;
  case _ETAPA_ :
      d->etapa = 0;
      while(strcmp(text, nomeEtapa[d->etapa])) d->etapa++;
      d->v = *valptr(d);
      pvPrintf(p,_INPUT_,"%g",d->v);
      break;
  case _INPUT_ :
      if(isValidDouble(text, &f)){
          f1 = f > d->vmax ? d->vmax : f < d->vmin ? d->vmin : f;
          if(f1 != f) pvPrintf(p,id,"%g",f1);
          d->v = f1;
      }
      else pvPrintf(p,id,"%g",d->v);
      break;
  }

  return 0;
}

static int slotSliderEvent(PARAM *p, int id, DATA *d, int val)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000) return -1;
  return 0;
}

static int slotCheckboxEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}

static int slotRadioButtonEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}

static int slotGlInitializeEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotGlPaintEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotGlResizeEvent(PARAM *p, int id, DATA *d, int width, int height)
{
  if(p == NULL || id == 0 || d == NULL || width < 0 || height < 0) return -1;
  return 0;
}

static int slotGlIdleEvent(PARAM *p, int id, DATA *d)
{
  if(p == NULL || id == 0 || d == NULL) return -1;
  return 0;
}

static int slotTabEvent(PARAM *p, int id, DATA *d, int val)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000) return -1;
  return 0;
}

static int slotTableTextEvent(PARAM *p, int id, DATA *d, int x, int y, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000 || text == NULL) return -1;
  return 0;
}

static int slotTableClickedEvent(PARAM *p, int id, DATA *d, int x, int y, int button)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000 || button < 0) return -1;
  return 0;
}

static int slotSelectionEvent(PARAM *p, int id, DATA *d, int val, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000 || text == NULL) return -1;
  return 0;
}

static int slotClipboardEvent(PARAM *p, int id, DATA *d, int val)
{
  if(p == NULL || id == -1 || d == NULL || val < -1000) return -1;
  return 0;
}

static int slotRightMouseEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  //pvPopupMenu(p,-1,"Menu1,Menu2,,Menu3");
  return 0;
}

static int slotKeyboardEvent(PARAM *p, int id, DATA *d, int val, int modifier)
{
  if(p == NULL || id == 0 || d == NULL || val < -1000 || modifier < -1000) return -1;
  return 0;
}

static int slotMouseMovedEvent(PARAM *p, int id, DATA *d, float x, float y)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000) return -1;
  return 0;
}

static int slotMousePressedEvent(PARAM *p, int id, DATA *d, float x, float y)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000) return -1;
  return 0;
}

static int slotMouseReleasedEvent(PARAM *p, int id, DATA *d, float x, float y)
{
  if(p == NULL || id == 0 || d == NULL || x < -1000 || y < -1000) return -1;
  return 0;
}

static int slotMouseOverEvent(PARAM *p, int id, DATA *d, int enter)
{
  if(p == NULL || id == 0 || d == NULL || enter < -1000) return -1;
  return 0;
}

static int slotUserEvent(PARAM *p, int id, DATA *d, const char *text)
{
  if(p == NULL || id == 0 || d == NULL || text == NULL) return -1;
  return 0;
}
