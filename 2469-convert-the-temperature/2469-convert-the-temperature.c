/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* convertTemperature(double celsius, int* returnSize) {
    *returnSize = 2;
    double* res = (double*)malloc(2 * sizeof(double));
    res[0] = celsius + 273.15; // Kelvin
    res[1] = celsius * 1.80 + 32.00; // Fahrenheit
    return res;
}
