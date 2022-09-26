import controlP5.*;

ControlP5 cp5;
int iter = 1000;
int stepCount = 0;
int myColor = color(0, 0, 0);
Button s = null, t = null;

void setup(){
  size(800, 800);
  background(110, 173, 247);
  cp5 = new ControlP5(this);
  
  cp5.addSlider("iter").setCaptionLabel("ITERATIONS").setPosition(250, 25).setSize(400, 30).setRange(1000, 500000);
  cp5.addSlider("stepCount").setCaptionLabel("STEP COUNT").setPosition(250, 55).setSize(400, 30).setRange(1, 1000);
  cp5.addButton("START").setValue(0).setPosition(15, 25).setSize(70, 40);
  t = cp5.addButton("GRADUAL").setValue(0).setPosition(100, 25).setSize(40, 30);
  s = cp5.addButton("COLOR").setValue(0).setPosition(150, 25).setSize(40, 30);
}

float wid = 400;
float hit = 400;
int j = 0, k = 0, stkNum = 0;
boolean gradual = false, happened = false, reset = false;
boolean fin = true;
boolean clr = false, tempClr = clr, start = false;
int range = 0;

void draw(){   
  strokeWeight(1);
  
  if(!gradual && reset){
    if(!happened){
      reset = false;
      for(int i = 0; i < iter; i++){
        if(tempClr){
          if(k < range)
            k++;
          if(k == range){
            stkNum++;
            k = 0;
          }
          
          stroke(stkNum);
        }
        else
          stroke(0);
        
        float a = random(0, 4);
        if(a > 0 && a <= 1){
          if(wid > width){
            line(wid, hit, wid - 1, hit);
            wid -= 1;
          }
          else{
            line(wid, hit, wid + 1, hit);
            wid += 1;
          }
        }
        else if(a > 1 && a <= 2){
          if(wid < 0){
            line(wid, hit, wid + 1, hit);
            wid += 1;
          }
          else{
            line(wid, hit, wid - 1, hit);
            wid -= 1;
          }
        }
        else if(a > 2 && a <=3){
          if(hit > height){
            line(wid, hit, wid, hit - 1);
            hit -= 1;
          }
          else{
            line(wid, hit, wid, hit + 1);
            hit += 1;
          }
        }
        else if(a > 3 && a <= 4){
          if(hit < 0){
            line(wid, hit, wid, hit + 1);
            hit += 1;
          }
          else{
            line(wid, hit, wid, hit - 1);
            hit -= 1;
          }
        }
      }
        happened = true;
        fin = true;
    }
  }
  else if(!fin){
    reset = false;
    for(int i = 0; i < stepCount; i++){
      float a = random(0, 4);
        if(tempClr){
          if(k < range)
            k++;
          if(k == range){
            stkNum++;
            k = 0;
          }
          
          stroke(stkNum);
        }
        else
          stroke(0);
        
      if(a > 0 && a <= 1){
          if(wid > width){
            line(wid, hit, wid - 1, hit);
            wid -= 1;
          }
          else{
            line(wid, hit, wid + 1, hit);
            wid += 1;
          }
        }
        else if(a > 1 && a <= 2){
          if(wid < 0){
            line(wid, hit, wid + 1, hit);
            wid += 1;
          }
          else{
            line(wid, hit, wid - 1, hit);
            wid -= 1;
          }
        }
        else if(a > 2 && a <=3){
          if(hit > height){
            line(wid, hit, wid, hit - 1);
            hit -= 1;
          }
          else{
            line(wid, hit, wid, hit + 1);
            hit += 1;
          }
        }
        else if(a > 3 && a <= 4){
          if(hit < 0){
            line(wid, hit, wid, hit + 1);
            hit += 1;
          }
          else{
            line(wid, hit, wid, hit - 1);
            hit -= 1;
          }
        }
      
      if(j < iter)
        j++;
      else if(j == iter){
        fin = true;
        j = 0;
        break;
      }
    }
  }
}

void START(){
  if(frameCount > 0){  
    background(110, 173, 247);
    line(width/2, height/2, width/2, height/2 + 2);
    hit = 400;
    wid = 400;
    reset = true;
    happened = false;
    fin = false;
    stkNum = 0;
    range = (iter / 255) + 1;
    k = 0;
    tempClr = clr;
    start = true;
  }
}

void GRADUAL(){
  if(frameCount > 0){
    gradual = !gradual;
    if(gradual){
      t.setColorBackground(color(0, 170, 255));
    }
    else if(!gradual){
      t.setColorBackground(color(0, 45, 90));
    }
    println("Gradual");
  }
}

void COLOR(){
  if(frameCount > 0){
    if(clr){
      clr = false;
      s.setColorBackground(color(0, 45, 90));
      //clr = !clr;
      println("this");
    }
    else if(!clr){
      clr = true;
      //s.setColorBackground(color(0, 45, 90));
      s.setColorBackground(color(0, 170, 255));
      println("that");
    }
  }
}
