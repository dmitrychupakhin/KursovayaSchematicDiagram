
namespace KursovayaSchematicDiagram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Collections::Generic;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Reflection;

	public ref struct SchematicDiagramElementType
	{
		String^ path;
		String^ name;
		String^ group;

		SchematicDiagramElementType (String^ path, String^ name, String^ group) 
			: path(path), name(name), group(group)
		{
		}
	};

	public ref class SchematicDiagramElementImageManager{
	private:
		Dictionary<int, SchematicDiagramElementType^>^ imageDictionary;
	public:
		SchematicDiagramElementImageManager() {
			imageDictionary = gcnew Dictionary<int, SchematicDiagramElementType^>();
			imageDictionary->Add(1, gcnew SchematicDiagramElementType("1", "Двухобмоточный трансформатор", "Силовые трансформаторы и автотрансформаторы"));
			imageDictionary->Add(2, gcnew SchematicDiagramElementType("2", "Двухобмоточный трансформатор с РПН", "Силовые трансформаторы и автотрансформаторы"));
			imageDictionary->Add(3, gcnew SchematicDiagramElementType("3", "Автотрансформатор", "Силовые трансформаторы и автотрансформаторы"));
			imageDictionary->Add(4, gcnew SchematicDiagramElementType("4", "Автотрансформатор С РПН", "Силовые трансформаторы и автотрансформаторы"));
			imageDictionary->Add(5, gcnew SchematicDiagramElementType("5", "Трёхобмоточный трансформатор", "Силовые трансформаторы и автотрансформаторы"));
			imageDictionary->Add(6, gcnew SchematicDiagramElementType("6", "Трёхобмоточный трансформатор С РПН", "Силовые трансформаторы и автотрансформаторы"));
			imageDictionary->Add(7, gcnew SchematicDiagramElementType("7", "Двухобмоточный трансформатор с расщепленной нижней обмоткой", "Силовые трансформаторы и автотрансформаторы"));
			imageDictionary->Add(8, gcnew SchematicDiagramElementType("8", "Двухобмоточный трансформатор с расщепленной нижней обмоткой С РПН", "Силовые трансформаторы и автотрансформаторы"));
			imageDictionary->Add(9, gcnew SchematicDiagramElementType("9", "Трансформатортокаизмерительный", "Силовые трансформаторы и автотрансформаторы"));
			imageDictionary->Add(10, gcnew SchematicDiagramElementType("10", "Трансформаторнапряжения", "Силовые трансформаторы и автотрансформаторы"));
		}

		SchematicDiagramElementType^ GetSchematicDiagramElement(int id) {
			if (imageDictionary->ContainsKey(id)) {
				return imageDictionary[id];
			}
			else {
				return nullptr;
			}
		}

		Dictionary<int, SchematicDiagramElementType^>^ GetImageDictionary() {
			return imageDictionary;
		}
	};
}