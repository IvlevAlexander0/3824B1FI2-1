
double lab_exp(double x, int n){
    double res = 0;
    double pow = 1;
    double factorial = 1;
    for(int i = 0; i < n; i++){
        res += (pow)/(factorial);
        if(i > 1){
            factorial *= i;
        }
        pow *= x;
    }
    return res;
}
