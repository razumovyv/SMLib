//------------------------------- File MultiDisplays.h ------------------------
#ifndef SML_MULTI_DISPLAYS_H_
#define SML_MULTI_DISPLAYS_H_


#include <vector>
#include <SMLib/System/NoneCopyable.h>
#include <SMLib/Video/Export.h>
#include <SMLib/Video/Display.h>

namespace sml { 
namespace video {

	class SML_VIDEO_API MultiDisplay : system::NoneCopyable {

		public:

			//-----------------------------------------------------------------
			// Destructor
			//-----------------------------------------------------------------
			~MultiDisplay( );

			//-----------------------------------------------------------------
			// Factory function for returning singleton
			//-----------------------------------------------------------------
			static MultiDisplay* 
			GetMultiDisplays( const bool useMultidisplay = SML_MD_PRIMARY_ONLY );

			//-----------------------------------------------------------------
			// Returnin nuber of display instances
			//-----------------------------------------------------------------
			size_t GetNumberDisplays() const;

			//-----------------------------------------------------------------
			// Returning a reference to a display instance
			//-----------------------------------------------------------------
			Display GetDisplayRef( const uint32_t& index ) const;



		private:
			
			//-----------------------------------------------------------------
			// Default constructor
			//-----------------------------------------------------------------
			MultiDisplay( );
			

			//-----------------------------------------------------------------
			// Conteiner for diaplys instances
			//-----------------------------------------------------------------
			std::vector< Display > displays_;

			//-----------------------------------------------------------------
			// Adding a display instance to a container
			//-----------------------------------------------------------------
			void RegInstance( const Display &regInst );

			//-----------------------------------------------------------------
			// Clear container with displays
			//-----------------------------------------------------------------
			void ClearDisplayInstances();

	}; // class DisplayAccess
} // namespace video
} // namespace sml
#endif // !SML_MULTI_DISPLAYS_H_
//---------------------------- End of file MultiDisplays.h --------------------