/*Anika Nawer*/
#include<bits/stdc++.h>
using namespace std;

float rk(float x, float y) {
    return x - y;
}
float rk2(float x, float y) {
    return sin(x);
}
float rk3(float x, float y) {
    return cos(x);
}
float rk4(float x,float y) {
    return x*x+2*x*y;
}


void DE() {
    float h,x,y,a,b;
    int ch;
    cout<<"Enter initial value of choice"<<endl;
    cout<<"1.Linear Equation"<<endl;
    cout<<"2.sinx"<<endl;
    cout<<"3.cosx"<<endl;
    cout<<"4.Polynomial"<<endl;

    cin>>ch;
    cout<<"Enter step size h"<<endl;
    cin>>h;
    cout<<"Enter initial value of x"<<endl;
    cin>>x;
     cout<<"Enter initial value of y"<<endl;
    cin>>y;
     cout<<"Enter initial value of interval"<<endl;
    cin>>a>>b;


   // float h = 0.1;
   // float x = 0;
   // float y = 1;
    int steps = (b - a) / h;
    cout << "x0" << " = " << x << "\n";
        cout << "y0" << " = " << y << "\n";



    if(ch==1){
      for (int i = 0; i <= steps; i++) {
        float k1 = h * rk(x, y);
        float k2 = h * rk(x + h / 2, y + k1 / 2);
        float k3 = h * rk(x + h / 2, y + k2 / 2);
        float k4 = h * rk(x + h, y + k3);

        x = x + h;
        y = y + ((1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4));
        cout << "x" << i + 1 << " = " << x << "\n";
        cout << "y" << i + 1 << " = " << y << "\n";


    }
    }
    else if(ch==2){
        for (int i = 0; i <= steps; i++) {
            float k1 = h * rk2(x, y);
            float k2 = h * rk2(x + h / 2, y + k1 / 2);
            float k3 = h * rk2(x + h / 2, y + k2 / 2);
            float k4 = h * rk2(x + h, y + k3);

            x = x + h;
            y = y + ((1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4));
            cout << "x" << i + 1 << " = " << x << "\n";
            cout << "y" << i + 1 << " = " << y << "\n";

        }
    }
    else if(ch==3){
        for (int i = 0; i <= steps; i++) {
            float k1 = h * rk3(x, y);
            float k2 = h * rk3(x + h / 2, y + k1 / 2);
            float k3 = h * rk3(x + h / 2, y + k2 / 2);
            float k4 = h * rk3(x + h, y + k3);

            x = x + h;
            y = y + ((1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4));
            cout << "x" << i + 1 << " = " << x << "\n";
            cout << "y" << i + 1 << " = " << y << "\n";

        }
    }
    else {
        for (int i = 0; i <= steps; i++) {
            float k1 = h * rk4(x, y);
            float k2 = h * rk4(x + h / 2, y + k1 / 2);
            float k3 = h * rk4(x + h / 2, y + k2 / 2);
            float k4 = h * rk4(x + h, y + k3);

            x = x + h;
            y = y + ((1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4));
            cout << "x" << i + 1 << " = " << x << "\n";
            cout << "y" << i + 1 << " = " << y << "\n";

        }
    }
}
/*Anika Nawer*/