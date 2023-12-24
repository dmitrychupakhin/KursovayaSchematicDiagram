#include "GraphicElement.h"

namespace KursovayaSchematicDiagram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Collections::Generic;
	using namespace System::Drawing;

	public ref class SchematicDiagramElement : GraphicElement {
		String^ name;
		String^ imagePath;
		String^ group;
	public:
		
        property String^ Name {
            String^ get() {
                return name;
            }
            void set(String^ value) {
                name = value;
            }
        }

        // Гетер и сетер для поля imagePath
        property String^ ImagePath {
            String^ get() {
                return imagePath;
            }
            void set(String^ value) {
                imagePath = value;
            }
        }

        // Гетер и сетер для поля group
        property String^ Group {
            String^ get() {
                return group;
            }
            void set(String^ value) {
                group = value;
            }
        }

        SchematicDiagramElement(String^ name, String^ imagePath, String^ group) {
			this->name = name;
			this->imagePath = imagePath;
			this->group = group;
        }

		virtual void drawing(Graphics^ g) override {
			int i = 10;
		}
	};
}