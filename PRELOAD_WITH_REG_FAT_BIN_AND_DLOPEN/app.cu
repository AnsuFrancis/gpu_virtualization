#include <stdio.h>
#include <cuda_runtime_api.h>

__global__ void mykernel(int *data){

  (*data)++;
}

int main(void)
{
    int numDevices;
    if (cudaGetDeviceCount(&numDevices) != cudaSuccess) {
        fprintf(stderr, "Error calling cudaGetDeviceCount\n");
        return -1;
    }
    printf("found %d devices\n", numDevices);
    cudaSetDevice(0);
    int *d_data, h_data = 0;
    cudaMalloc((void **)&d_data, sizeof(int));
    cudaMemcpy(d_data, &h_data, sizeof(int), cudaMemcpyHostToDevice);
    mykernel<<<1,1>>>(d_data);
    cudaMemcpy(&h_data, d_data, sizeof(int), cudaMemcpyDeviceToHost);
    printf("data = %d\n", h_data);
    printf("Exceuted\n");
    return 0;
}
