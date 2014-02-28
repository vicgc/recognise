__kernel void vector_add(__global int *A, __global int *B, __global int *C) {
    
    // Get the index of the current element
    int i = get_global_id(0);

    // Do the operation
    C[i] = A[i] + B[i];
}

__kernel void taskParrallelSub(__global float *A, __global float *B, __global float *C) {
    int base = 1;

    C[base+0] = A[base+0] - B[base+0];
    C[base+4] = A[base+4] - b[base+4];
}


__kernel void dataParallel(__global float *A, __global float *B, __global float *C) {
        int base = 4*get_global_id(0);
        C[base+0] = A[base+0] + B[base+0];
        C[base+1] = A[base+1] - B[base+1];
        C[base+2] = A[base+2] * B[base+2];
        C[base+3] = A[base+3] / B[base+3];
}


__kernel void runRecogniser(__global float *imageVal) {

}
