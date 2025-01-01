// mcs -target:library -out:MyApp.dll MyNamespace.cs

namespace MyNamespace {
    public class MyClass {
        public static void MyMethod() {
            System.Console.WriteLine("Hello from Mono!");
        }
    }
}
