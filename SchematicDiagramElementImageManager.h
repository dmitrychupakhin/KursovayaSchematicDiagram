
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
			imageDictionary->Add(1, gcnew SchematicDiagramElementType("1", "�������������� �������������", "������� �������������� � ������������������"));
			imageDictionary->Add(2, gcnew SchematicDiagramElementType("2", "�������������� ������������� � ���", "������� �������������� � ������������������"));
			imageDictionary->Add(3, gcnew SchematicDiagramElementType("3", "�����������������", "������� �������������� � ������������������"));
			imageDictionary->Add(4, gcnew SchematicDiagramElementType("4", "����������������� � ���", "������� �������������� � ������������������"));
			imageDictionary->Add(5, gcnew SchematicDiagramElementType("5", "������������� �������������", "������� �������������� � ������������������"));
			imageDictionary->Add(6, gcnew SchematicDiagramElementType("6", "������������� ������������� � ���", "������� �������������� � ������������������"));
			imageDictionary->Add(7, gcnew SchematicDiagramElementType("7", "�������������� ������������� � ������������ ������ ��������", "������� �������������� � ������������������"));
			imageDictionary->Add(8, gcnew SchematicDiagramElementType("8", "�������������� ������������� � ������������ ������ �������� � ���", "������� �������������� � ������������������"));
			imageDictionary->Add(9, gcnew SchematicDiagramElementType("9", "������������������������������", "������� �������������� � ������������������"));
			imageDictionary->Add(10, gcnew SchematicDiagramElementType("10", "�����������������������", "������� �������������� � ������������������"));
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