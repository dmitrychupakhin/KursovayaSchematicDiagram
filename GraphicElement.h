namespace KursovayaSchematicDiagram {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Collections::Generic;
	using namespace System::Drawing;

	public ref class GraphicElement {
    protected:
		property int x;
		property int y;
	public:
        property int X
        {
            int get()
            {
                return x;
            }
            void set(int value)
            {
                x = value;
            }
        }

        property int Y
        {
            int get()
            {
                return y;
            }
            void set(int value)
            {
                y = value;
            }
        }

		virtual void drawing(Graphics^ g) = 0;
	};
}