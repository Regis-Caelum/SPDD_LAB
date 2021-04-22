
void Triangle(int a,int b,int c){

    int Perimeter = a+b+c;
    int s = (a+b+c)/2;
    int Area = sqrt(s*(s-a)*(s-b)*(s-c));

    printf("Perimeter of Tri: %d\n",Perimeter);
    printf("Area of Tri: %d\n",Area);

}


void Square(float a){
    printf("Perimeter of Sq: %.2f\n",4*a);
    printf("Area of Sq: %.2f\n",a*a);
}

void Circle(float radius){
    float perimeter = 2*3.14*radius;

    float area = 3.14*radius*radius;

    printf("Perimeter of Circle: %.2f\n",perimeter);
    printf("Area of Circle: %.2f\n",area);
}
