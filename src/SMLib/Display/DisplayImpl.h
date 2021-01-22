//--------------------- File DisplayImpl.h -----------------------------
#ifndef SML_DISPLAY_IMPLEMENTATION_H_
#define SML_DISPLAY_IMPLEMENTATION_H_
namespace sml{
    namespace cls{
            class DisplayImpl{
                public:
                    //--------------------------------------------------
                    // Default constructor
                    //--------------------------------------------------
                    DisplayImpl();
                    //--------------------------------------------------
                    // Distructor
                    //--------------------------------------------------
                    virtual ~DisplayImpl();

                    //--------------------------------------------------
                    // Disable the cope constructor
                    //--------------------------------------------------
                    DisplayImpl(const Display&) = delete;

                    //--------------------------------------------------
                    // Disable th assigment operator
                    //--------------------------------------------------
                    DisplayImpl& operator=(const DisplayImpl&) = delete;
                    

            };
    } // namespace cls
} // namespace sml
#endif
//------------------ End of file DisplayImpl.h -------------------------
