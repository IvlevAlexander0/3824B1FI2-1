
double lab_arcsin(double x, int n){
    double res = x;
    double pow = x*x*x;
    double factorial = 1;
    double factorial2 = 2;
    for(int i = 1; i <= n; i++){
        res += (pow*factorial)/(factorial2*(2*i-1));
        pow *= x*x;
        factorial *= 2*i-1;
        factorial2 *= 2*i;
    }
    return res;
}