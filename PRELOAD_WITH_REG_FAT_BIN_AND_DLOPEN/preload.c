#include <cuda_runtime_api.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void** __cudaRegisterFatBinary(void *cubin)
{
    printf("%s called from preload\n", __func__);

    void *cuda_handle;
    void** (*regFatBin)(void *);

    cuda_handle = dlopen ("libcudart.so", RTLD_NOW);
    if (!cuda_handle) {
        fputs (dlerror(), stderr); 
        exit(1);
    }
    regFatBin = dlsym(cuda_handle,  "__cudaRegisterFatBinary");
    return (*regFatBin)(cubin);
}
cudaError_t cudaGetDeviceCount(int * count)
{
    cudaError_t ret = cudaSuccess;
    printf("%s called from preload\n", __func__);
    if (count) {
        *count = 1337;
    } else {
        ret = cudaErrorInvalidValue;
    }
    return ret;
}
cudaError_t cudaSetDevice(int device)
{
    printf("%s called from preload\n", __func__);
    return cudaSuccess;
}
