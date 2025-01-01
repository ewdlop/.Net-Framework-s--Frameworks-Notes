#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>

int main(int argc, char* argv[]) {
    MonoDomain* domain;
    MonoAssembly* assembly;
    MonoImage* image;

    // Initialize the Mono runtime
    domain = mono_jit_init("MyAppDomain");

    // Load a C# assembly
    assembly = mono_domain_assembly_open(domain, "MyApp.dll");a
    if (!assembly) {
        printf("Could not open assembly!\n");
        return -1;
    }

    // Get the image of the assembly
    image = mono_assembly_get_image(assembly);

    // Invoke a method in the assembly
    MonoMethodDesc* desc = mono_method_desc_new("MyNamespace.MyClass:MyMethod", true);
    MonoMethod* method = mono_method_desc_search_in_image(desc, image);
    mono_method_desc_free(desc);

    if (!method) {
        printf("Could not find method!\n");
        return -1;
    }

    MonoObject* result = mono_runtime_invoke(method, NULL, NULL, NULL);

    // Cleanup the Mono runtime
    mono_jit_cleanup(domain);

    return 0;
}
