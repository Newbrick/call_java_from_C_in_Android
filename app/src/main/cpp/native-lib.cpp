#include <jni.h>
#include <string>

extern "C"
jstring
Java_com_callback_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    static int once = 1;
    if (once) {
        jclass dataClass = env->FindClass("com/callback/MainActivity");
        jclass javaClassRef = (jclass) env->NewGlobalRef(dataClass);

        jmethodID  javaMethodRef = env->GetStaticMethodID(javaClassRef, "callbackFromC", "(I)V");
        //jobject javaObjectRef = env->NewObject(javaClassRef, javaMethodRef);
        env->CallStaticVoidMethod(javaClassRef, javaMethodRef);
        once = 0;
    }


    return env->NewStringUTF(hello.c_str());
}
