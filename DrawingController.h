#include "SchematicDiagramElementImageManager.h"
#include "SchematicDiagramElement.h"


namespace KursovayaSchematicDiagram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Collections::Generic;
	using namespace System::Drawing;
	using namespace System::Reflection;
	using namespace System::Resources;
	using namespace System::Globalization;


	public ref class DrawingController {
	private:

		SchematicDiagramElementImageManager^ schematicDiagramElementImageManager;
		List<GraphicElement^>^ graphicsElements;
	public:
		DrawingController() {
			schematicDiagramElementImageManager = gcnew SchematicDiagramElementImageManager();
			graphicsElements = gcnew List<GraphicElement^>();
		}

		Void AddSchematicDiagramElement(int id) {
			SchematicDiagramElementType^ elementPair = schematicDiagramElementImageManager->GetSchematicDiagramElement(id);
			graphicsElements->Add(gcnew SchematicDiagramElement(elementPair->name, elementPair->path, elementPair->group));
		}

		Void UpdateTreeView(TreeView^ treeView, ImageList^ imageList) {
			treeView->ImageList = imageList;
			imageList->ImageSize = Drawing::Size(32, 32);

			for each (KeyValuePair<int, SchematicDiagramElementType^> kvp in schematicDiagramElementImageManager->GetImageDictionary()) {

				System::Resources::ResourceManager^ rc = gcnew
					System::Resources::ResourceManager("KursovayaSchematicDiagram.Resources", Reflection::Assembly::GetExecutingAssembly());

				imageList->Images->Add(kvp.Value->path, safe_cast<Bitmap^>(rc->GetObject(kvp.Value->path)));

				bool isFind = false;

				for each (TreeNode^ group in treeView->Nodes) {
					if (group->Text == kvp.Value->group) {
						TreeNode^ node = gcnew TreeNode(kvp.Value->name);
						node->ImageKey = kvp.Value->path;
						node->SelectedImageKey = kvp.Value->path;
						group->Nodes->Add(node);
						isFind = true;
						break;
					}
				}
				if (!isFind) {
					TreeNode^ group = gcnew TreeNode(kvp.Value->group);
					TreeNode^ node = gcnew TreeNode(kvp.Value->name);
					node->ImageKey = kvp.Value->path;
					node->SelectedImageKey = kvp.Value->path;
					group->SelectedImageKey = kvp.Value->path;
					group->Nodes->Add(node);
					treeView->Nodes->Add(group);
				}

			}
		}
	};
}