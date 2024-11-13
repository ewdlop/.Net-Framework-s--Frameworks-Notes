# .Net-Framework(s)--Framework(s)-Note)s

https://discussions.unity.com/t/what-is-mono-is-it-a-compiler-a-language-or-what/423/3

## 

~~https://www.reddit.com/r/gamedev/comments/qu078d/microsoft_xna/~~

https://monogame.net/

## Prior to .Net Core 1.0 < .Net 5

https://learn.microsoft.com/en-us/dotnet/framework/

##

To use a **.NET Framework** library in a **.NET Core** or **.NET (5, 6, 7, 8)** application, you can follow several methods depending on compatibility and the library’s requirements. Here are some approaches to help you work with .NET Framework libraries in a modern .NET environment:

### 1. **Check Compatibility with .NET Standard**

- **.NET Standard** acts as a bridge between .NET Framework, .NET Core, and .NET. If the .NET Framework library supports .NET Standard, you can use it directly in .NET Core or .NET projects.
- **How to Check**: Open the `.csproj` file of the .NET Framework library and check if it targets `.NET Standard`. If it does, you can add it as a reference in your .NET Core/.NET project without issues.

#### Example
```xml
<TargetFramework>netstandard2.0</TargetFramework>
```

### 2. **Use the .NET Framework Library Directly (Only for Compatible Versions)**

If the .NET Framework library does not target .NET Standard but targets .NET Framework 4.6.1 or above, it may be usable in .NET Core 2.0+ and .NET 5+. This approach works because .NET Core 2.0 and later versions have compatibility support for .NET Framework libraries from version 4.6.1 onward.

- **Limitations**: This approach works for libraries without Windows-specific dependencies (e.g., `System.Web`, `System.Drawing`).
- **How to Use**: Add the .NET Framework DLL as a reference in your .NET Core/.NET project. In Visual Studio, right-click on **Dependencies** > **Add Reference...** and browse for the DLL.

### 3. **Use Windows Compatibility Pack for Windows-Specific Dependencies**

For .NET Core and .NET (5, 6, etc.) applications on **Windows**, you can install the **Windows Compatibility Pack** (`Microsoft.Windows.Compatibility`), which provides many Windows-only APIs from .NET Framework.

- **Install the Compatibility Pack**:
  ```bash
  dotnet add package Microsoft.Windows.Compatibility
  ```

- **Supported APIs**: This pack includes various Windows APIs, but not all. For example, it provides APIs like `System.Drawing` and some Windows registry APIs.

### 4. **Port the Library to .NET Standard or .NET Core**

If the library is open-source or you have access to its code, you can port it to target `.NET Standard` or `.NET` directly:

1. **Create a new .NET Standard or .NET Class Library** project.
2. Copy over the code from the .NET Framework library.
3. Update any incompatible APIs with compatible ones, as .NET Core/.NET has different API support.
4. Build the library and reference it in your .NET Core/.NET application.

This approach is more work-intensive but creates a future-proof version of the library.

### 5. **Use .NET Core-Compatible Alternatives**

In some cases, it may be more feasible to replace the .NET Framework library with a .NET Core or .NET-compatible alternative library.

- **Common Alterna
- Creatives**: Many popular .NET Framework libraries (e.g., `System.Data.SqlClient`, `System.Net.Http`) have `.NET Core` or `.NET` versions, often found as NuGet packages with similar functionality.
- **NuGet Search**: Check for `.NET Core` versions of the library on [NuGet.org](https://www.nuget.org/).

### 6. **Wrap the Library in a COM or REST API for Interoperability**

If you cannot port or directly reference the library and if it depends heavily on Windows, you can create a **COM wrapper** or expose it as a **REST API**:

- **COM Wrapper**: Use COM Interop to expose the .NET Framework library as a COM object, then call it from your .NET Core or .NET application.
- **REST API Wrapper**: Create a small .NET Framework service that exposes the library’s functionality over HTTP. Your .NET Core/.NET application can then call this API.

# 7. **Using a .NET Framework Library in a .NET Core/NET Windows-Only Application**

If your application targets **Windows only**, and you need to use a .NET Framework library with platform-specific code, ensure the `.csproj` includes the **`<RuntimeIdentifier>`** for Windows.

#### Example Project File (`.csproj`)

```xml
<Project Sdk="Microsoft.NET.Sdk">
  <PropertyGroup>
    <TargetFramework>net5.0-windows</TargetFramework>
    <RuntimeIdentifier>win10-x64</RuntimeIdentifier>
  </PropertyGroup>

  <ItemGroup>
    <Reference Include="Path\To\Your\DotNetFrameworkLibrary.dll" />
  </ItemGroup>
</Project>
```

### Summary of Approaches

| Approach                             | Best for                                      |
|--------------------------------------|-----------------------------------------------|
| **.NET Standard**                    | If the library supports .NET Standard         |
| **Direct Reference**                 | If it targets .NET Framework 4.6.1+           |
| **Windows Compatibility Pack**       | For Windows-specific APIs                     |
| **Port to .NET Standard/Core**       | If you have the library source code           |
| **Use Alternatives**                 | When a .NET Core/.NET equivalent exists       |
| **COM/REST API Wrapper**             | When you need inter-process communication     |
| **Windows-Only Runtime Identifier**  | Windows-specific, .NET 5+ or .NET Core 3.1    |

This process allows you to integrate .NET Framework libraries into modern .NET applications with minimal compatibility issues.
