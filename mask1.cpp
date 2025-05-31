////////////////////////////////////////////////////////////////////////////
//
// show_mask1 for ProcessViewServer created: dom. mai. 11 18:39:57 2025
//
////////////////////////////////////////////////////////////////////////////
#include "pvapp.h"

// _begin_of_generated_area_ (do not edit -> use ui2pvc) -------------------

// our mask contains the following objects
enum {
  ID_MAIN_WIDGET = 0,
  _ETAPA_,
  _VAL_,
  _INPUT_,
  _PREFALTA_,
  _FALTA_,
  _POSFALTA_,
  _MEDIDAS_,
  _START_,
  _DI0_,
  _DI1_,
  _TIMER_,
  _SECONDS_,
  _DO0_,
  _DO1_,
  ID_END_OF_WIDGETS
};

// our mask contains the following widget names
  static const char *widgetName[] = {
  "ID_MAIN_WIDGET",
  "_ETAPA_",
  "_VAL_",
  "_INPUT_",
  "_PREFALTA_",
  "_FALTA_",
  "_POSFALTA_",
  "_MEDIDAS_",
  "_START_",
  "_DI0_",
  "_DI1_",
  "_TIMER_",
  "_SECONDS_",
  "_DO0_",
  "_DO1_",
  "ID_END_OF_WIDGETS",
  ""};

  static const char *toolTip[] = {
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  ""};

  static const char *whatsThis[] = {
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  ""};

  static const int widgetType[ID_END_OF_WIDGETS+1] = {
  0,
  TQComboBox,
  TQComboBox,
  TQLineEdit,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLabel,
  TQPushButton,
  TQLabel,
  TQLabel,
  TQLabel,
  TQLCDNumber,
  TQPushButton,
  TQPushButton,
  -1 };

static int generated_defineMask(PARAM *p)
{
  int w,h,depth;

  if(p == NULL) return 1;
  if(widgetName[0] == NULL) return 1; // suppress unused warning
  w = h = depth = strcmp(toolTip[0],whatsThis[0]);
  if(widgetType[0] == -1) return 1;
  if(w==h) depth=0; // fool the compiler
  pvStartDefinition(p,ID_END_OF_WIDGETS);

  pvQComboBox(p,_ETAPA_,0,0,AtBottom);
  pvSetGeometry(p,_ETAPA_,15,9,254,30);
  pvSetFont(p,_ETAPA_,"Ubuntu",11,0,0,0,0);

  pvQComboBox(p,_VAL_,0,0,AtBottom);
  pvSetGeometry(p,_VAL_,15,45,149,30);
  pvSetFont(p,_VAL_,"Ubuntu",11,0,0,0,0);

  pvQLineEdit(p,_INPUT_,0);
  pvSetGeometry(p,_INPUT_,168,45,99,30);
  pvSetText(p,_INPUT_,pvtr("115"));
  pvSetFont(p,_INPUT_,"Ubuntu",11,0,0,0,0);

  pvQLabel(p,_PREFALTA_,0);
  pvSetGeometry(p,_PREFALTA_,9,159,270,144);
  pvSetText(p,_PREFALTA_,pvtr("Label"));
  pvSetFont(p,_PREFALTA_,"Ubuntu",11,0,0,0,0);
  pvSetStyle(p,_PREFALTA_,Box,-1,-1,-1);

  pvQLabel(p,_FALTA_,0);
  pvSetGeometry(p,_FALTA_,285,159,270,144);
  pvSetText(p,_FALTA_,pvtr("Label"));
  pvSetFont(p,_FALTA_,"Ubuntu",11,0,0,0,0);
  pvSetStyle(p,_FALTA_,Box,-1,-1,-1);

  pvQLabel(p,_POSFALTA_,0);
  pvSetGeometry(p,_POSFALTA_,561,159,270,144);
  pvSetText(p,_POSFALTA_,pvtr("Label"));
  pvSetFont(p,_POSFALTA_,"Ubuntu",11,0,0,0,0);
  pvSetStyle(p,_POSFALTA_,Box,-1,-1,-1);

  pvQLabel(p,_MEDIDAS_,0);
  pvSetGeometry(p,_MEDIDAS_,285,9,270,144);
  pvSetText(p,_MEDIDAS_,pvtr("Label"));
  pvSetFont(p,_MEDIDAS_,"Courier",11,0,0,0,0);
  pvSetStyle(p,_MEDIDAS_,Box,-1,-1,-1);

  pvQPushButton(p,_START_,0);
  pvSetGeometry(p,_START_,600,111,99,30);
  pvSetText(p,_START_,pvtr("START"));
  pvSetFont(p,_START_,"Ubuntu",11,0,0,0,0);

  pvQLabel(p,_DI0_,0);
  pvSetGeometry(p,_DI0_,123,81,99,30);
  pvSetText(p,_DI0_,pvtr("DI0 OFF"));
  pvSetFont(p,_DI0_,"Ubuntu",11,0,0,0,0);
  pvSetStyle(p,_DI0_,Box,-1,-1,-1);

  pvQLabel(p,_DI1_,0);
  pvSetGeometry(p,_DI1_,123,117,99,30);
  pvSetText(p,_DI1_,pvtr("DI1 OFF"));
  pvSetFont(p,_DI1_,"Ubuntu",11,0,0,0,0);
  pvSetStyle(p,_DI1_,Box,-1,-1,-1);

  pvQLabel(p,_TIMER_,0);
  pvSetGeometry(p,_TIMER_,708,111,99,30);
  pvSetText(p,_TIMER_,pvtr("TIMER OFF"));
  pvSetFont(p,_TIMER_,"Ubuntu",11,0,0,0,0);
  pvSetStyle(p,_TIMER_,Box,-1,-1,-1);

  pvQLCDNumber(p,_SECONDS_,0,6,Filled,Dec);
  pvSetGeometry(p,_SECONDS_,633,66,144,39);
  pvSetFont(p,_SECONDS_,"Ubuntu",11,0,0,0,0);

  pvQPushButton(p,_DO0_,0);
  pvSetGeometry(p,_DO0_,15,81,99,30);
  pvSetText(p,_DO0_,pvtr("DO0"));
  pvSetFont(p,_DO0_,"Ubuntu",11,0,0,0,0);

  pvQPushButton(p,_DO1_,0);
  pvSetGeometry(p,_DO1_,15,117,99,30);
  pvSetText(p,_DO1_,pvtr("DO1"));
  pvSetFont(p,_DO1_,"Ubuntu",11,0,0,0,0);


  pvEndDefinition(p);
  return 0;
}

// _end_of_generated_area_ (do not edit -> use ui2pvc) ---------------------

enum {PREFALTA, FALTA, POSFALTA};
enum {TENSAO, CORRENTE, ANGULO, FREQUENCIA, TEMPO};

#include "mask1_slots.h"

CMT v;

float *valptr(DATA *d)
{
  switch(d->etapa){
    case PREFALTA:
      switch(d->val){
        case TENSAO     : return &d->u0;
        case CORRENTE   : return &d->i0;
        case ANGULO     : return &d->teta0;
        case FREQUENCIA : return &d->f0;
        case TEMPO      : return &d->t0;
      } break;
    case FALTA:
      switch(d->val){
        case TENSAO     : return &d->u1;
        case CORRENTE   : return &d->i1;
        case ANGULO     : return &d->teta1;
        case FREQUENCIA : return &d->f1;
        case TEMPO      : return &d->t1;
      } break;
    case POSFALTA:
      switch(d->val){
        case TENSAO     : return &d->u2;
        case CORRENTE   : return &d->i2;
        case ANGULO     : return &d->teta2;
        case FREQUENCIA : return &d->f2;
        case TEMPO      : return &d->t2;
      }
  }
  return NULL;
}

// Função para verificar se uma string representa um número de ponto flutuante válido
// Retorna 1 se for válido, 0 caso contrário.
int isValidDouble(const char *str, double *value) {
    if (str == NULL || *str == '\0') { // Verifica se a string é nula ou vazia
        return 0;
    }

    char *endptr; // Ponteiro para o caractere onde a conversão parou
    errno = 0;    // Limpa errno antes da chamada para detectar erros específicos

    // Converte a string para double
     *value = strtod(str, &endptr);

    // 1. Verifica se a conversão foi bem-sucedida e se toda a string foi consumida
    //    *endptr == '\0' significa que todos os caracteres foram parte do número.
    //    str != endptr significa que pelo menos um caractere foi convertido (não é string vazia ou só espaços).
    if (*endptr != '\0' || str == endptr) {
        return 0; // Não é um número válido (ou contém caracteres extras, ou é vazia/só espaços)
    }

    // 2. Verifica se houve erros de overflow/underflow (valor muito grande/pequeno para double)
    if (errno == ERANGE) {
        // O valor excedeu os limites de um double
        // printf("Erro: Valor fora da faixa representável para double.\n");
        return 0;
    }

    // A string é um número de ponto flutuante válido
    return 1;
}


static int defineMask(PARAM *p)
{
  if(p == NULL) return 1;
  generated_defineMask(p);

  // (todo: add your code here)
  return 0;
}


static int showData(PARAM *p, DATA *d)
{
  if(p == NULL) return 1;
  if(d == NULL) return 1;

  pvPrintf(p,_DI0_,"DI0 %s", v.DI0 ? "ON" : "OFF");
  if(v.DI0) pvSetBackgroundColor(p,_DI0_, 0xff, 0xff, 0xff);
  else      pvSetBackgroundColor(p,_DI0_, BG_COLOR);
  pvPrintf(p,_DI1_,"DI1 %s", v.DI1 ? "ON" : "OFF");
  if(v.DI1) pvSetBackgroundColor(p,_DI1_, 0xff, 0xff, 0xff);
  else      pvSetBackgroundColor(p,_DI1_, BG_COLOR);
  pvPrintf(p,_TIMER_,"TIMER %s", v.Status ? "ON" : "OFF");
  if(v.Status) pvSetBackgroundColor(p,_TIMER_, 0xff, 0xff, 0xff);
  else         pvSetBackgroundColor(p,_TIMER_, BG_COLOR);
//  pvDisplayFloat(p, _SECONDS_, d->F0 < 3 && !(d->d ? --d->d : d->d) ? (unsigned short)v.Timer*0.001 : 0);
  char buf[16];
  sprintf(buf, "%6.3f", d->F0 < 3 && !(d->d ? --d->d : d->d) ? (unsigned short)v.Timer*0.001 : 0);
  pvDisplayStr(p, _SECONDS_, buf);
 
  pvPrintf(p, _PREFALTA_, "PRÉ-FALTA\n\nTensão : %g V\nCorrente : %g A\nÂngulo : %g°\nFrequência : %g Hz\nDuração : %g s", d->u0, d->i0, d->teta0, d->f0, d->t0);
  pvPrintf(p, _FALTA_,    "FALTA\n\nTensão : %g V\nCorrente : %g A\nÂngulo : %g°\nFrequência : %g Hz\nDuração : %g s", d->u1, d->i1, d->teta1, d->f1, d->t1);
  pvPrintf(p, _POSFALTA_, "PÓS-FALTA\n\nTensão : %g V\nCorrente : %g A\nÂngulo : %g°\nFrequência : %g Hz\nDuração : %g s", d->u2, d->i2, d->teta2, d->f2, d->t2);

  pvPrintf(p, _MEDIDAS_, "V1 =%7g ∠%5g° V\nV2 =%7g ∠%5g° V\nV3 =%7g ∠%5g° V\n" \
                         "I1 =%7g ∠%5g° A\nI2 =%7g ∠%5g° A\nI3 =%7g ∠%5g° A", 
                         v.V1*0.01,  v.argV1*0.1, v.V2*0.01,  v.argV2*0.1, v.V3*0.01,  v.argV3*0.1,
                         v.I1*0.001, v.argI1*0.1, v.I2*0.001, v.argI2*0.1, v.I3*0.001, v.argI3*0.1);

  return 0;
}

static int readData(DATA *d) // from shared memory, database or something else
{
  if(d == NULL) return 1;
  // (todo: add your code here)

  short *vp = (short *)&v;
  for(long unsigned int i = 0; i < sizeof(CMT)/2; i++){
      vp[i] = modbus.readShort(0,i);
  }

  return 0;
}


int show_mask1(PARAM *p)
{
  DATA d;
  char event[MAX_EVENT_LENGTH];
  char text[MAX_EVENT_LENGTH];
  char str1[MAX_EVENT_LENGTH];
  int  i,w,h,val,x,y,button,ret;
  float xval, yval;

  defineMask(p);
  //rlSetDebugPrintf(1);
  if((ret=slotInit(p,&d)) != 0) return ret;
  readData(&d); // from shared memory, database or something else
  showData(p,&d);
  pvClearMessageQueue(p);
  while(1)
  {
    pvPollEvent(p,event);
    switch(pvParseEvent(event, &i, text))
    {
      case NULL_EVENT:
        readData(&d); // from shared memory, database or something else
        showData(p,&d);
        if((ret=slotNullEvent(p,&d)) != 0) return ret;
        break;
      case BUTTON_EVENT:
        if(trace) printf("BUTTON_EVENT id=%d\n",i);
        if((ret=slotButtonEvent(p,i,&d)) != 0) return ret;
        break;
      case BUTTON_PRESSED_EVENT:
        if(trace) printf("BUTTON_PRESSED_EVENT id=%d\n",i);
        if((ret=slotButtonPressedEvent(p,i,&d)) != 0) return ret;
        break;
      case BUTTON_RELEASED_EVENT:
        if(trace) printf("BUTTON_RELEASED_EVENT id=%d\n",i);
        if((ret=slotButtonReleasedEvent(p,i,&d)) != 0) return ret;
        break;
      case TEXT_EVENT:
        if(trace) printf("TEXT_EVENT id=%d %s\n",i,text);
        if((ret=slotTextEvent(p,i,&d,text)) != 0) return ret;
        break;
      case SLIDER_EVENT:
        sscanf(text,"(%d)",&val);
        if(trace) printf("SLIDER_EVENT val=%d\n",val);
        if((ret=slotSliderEvent(p,i,&d,val)) != 0) return ret;
        break;
      case CHECKBOX_EVENT:
        if(trace) printf("CHECKBOX_EVENT id=%d %s\n",i,text);
        if((ret=slotCheckboxEvent(p,i,&d,text)) != 0) return ret;
        break;
      case RADIOBUTTON_EVENT:
        if(trace) printf("RADIOBUTTON_EVENT id=%d %s\n",i,text);
        if((ret=slotRadioButtonEvent(p,i,&d,text)) != 0) return ret;
        break;
      case GL_INITIALIZE_EVENT:
        if(trace) printf("you have to call initializeGL()\n");
        if((ret=slotGlInitializeEvent(p,i,&d)) != 0) return ret;
        break;
      case GL_PAINT_EVENT:
        if(trace) printf("you have to call paintGL()\n");
        if((ret=slotGlPaintEvent(p,i,&d)) != 0) return ret;
        break;
      case GL_RESIZE_EVENT:
        sscanf(text,"(%d,%d)",&w,&h);
        if(trace) printf("you have to call resizeGL(w,h)\n");
        if((ret=slotGlResizeEvent(p,i,&d,w,h)) != 0) return ret;
        break;
      case GL_IDLE_EVENT:
        if((ret=slotGlIdleEvent(p,i,&d)) != 0) return ret;
        break;
      case TAB_EVENT:
        sscanf(text,"(%d)",&val);
        if(trace) printf("TAB_EVENT(%d,page=%d)\n",i,val);
        if((ret=slotTabEvent(p,i,&d,val)) != 0) return ret;
        break;
      case TABLE_TEXT_EVENT:
        sscanf(text,"(%d,%d,",&x,&y);
        pvGetText(text,str1);
        if(trace) printf("TABLE_TEXT_EVENT(%d,%d,\"%s\")\n",x,y,str1);
        if((ret=slotTableTextEvent(p,i,&d,x,y,str1)) != 0) return ret;
        break;
      case TABLE_CLICKED_EVENT:
        sscanf(text,"(%d,%d,%d)",&x,&y,&button);
        if(trace) printf("TABLE_CLICKED_EVENT(%d,%d,button=%d)\n",x,y,button);
        if((ret=slotTableClickedEvent(p,i,&d,x,y,button)) != 0) return ret;
        break;
      case SELECTION_EVENT:
        sscanf(text,"(%d,",&val);
        pvGetText(text,str1);
        if(trace) printf("SELECTION_EVENT(column=%d,\"%s\")\n",val,str1);
        if((ret=slotSelectionEvent(p,i,&d,val,str1)) != 0) return ret;
        break;
      case CLIPBOARD_EVENT:
        sscanf(text,"(%d",&val);
        if(trace) printf("CLIPBOARD_EVENT(id=%d)\n",val);
        if((ret=slotClipboardEvent(p,i,&d,val)) != 0) return ret;
        break;
      case RIGHT_MOUSE_EVENT:
        if(trace) printf("RIGHT_MOUSE_EVENT id=%d text=%s\n",i,text);
        if((ret=slotRightMouseEvent(p,i,&d,text)) != 0) return ret;
        break;
      case KEYBOARD_EVENT:
        sscanf(text,"(%d",&val);
        if(trace) printf("KEYBOARD_EVENT modifier=%d key=%d\n",i,val);
        if((ret=slotKeyboardEvent(p,i,&d,val,i)) != 0) return ret;
        break;
      case PLOT_MOUSE_MOVED_EVENT:
        sscanf(text,"(%f,%f)",&xval,&yval);
        if(trace) printf("PLOT_MOUSE_MOVE %f %f\n",xval,yval);
        if((ret=slotMouseMovedEvent(p,i,&d,xval,yval)) != 0) return ret;
        break;
      case PLOT_MOUSE_PRESSED_EVENT:
        sscanf(text,"(%f,%f)",&xval,&yval);
        if(trace) printf("PLOT_MOUSE_PRESSED %f %f\n",xval,yval);
        if((ret=slotMousePressedEvent(p,i,&d,xval,yval)) != 0) return ret;
        break;
      case PLOT_MOUSE_RELEASED_EVENT:
        sscanf(text,"(%f,%f)",&xval,&yval);
        if(trace) printf("PLOT_MOUSE_RELEASED %f %f\n",xval,yval);
        if((ret=slotMouseReleasedEvent(p,i,&d,xval,yval)) != 0) return ret;
        break;
      case MOUSE_OVER_EVENT:
        sscanf(text,"%d",&val);
        if(trace) printf("MOUSE_OVER_EVENT %d\n",val);
        if((ret=slotMouseOverEvent(p,i,&d,val)) != 0) return ret;
        break;
      case USER_EVENT:
        if(trace) printf("USER_EVENT id=%d %s\n",i,text);
        if((ret=slotUserEvent(p,i,&d,text)) != 0) return ret;
        break;
      default:
        if(trace) printf("UNKNOWN_EVENT id=%d %s\n",i,text);
        break;
    }
  }
}
