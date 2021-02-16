//------------------------------- File MultiDisplays.h ------------------------
#ifndef SML_MULTI_DISPLAYS_H_
#define SML_MULTI_DISPLAYS_H_


#include <map>
#include <SMLib/System/NoneCopyable.h>
#include <SMLib/Video/Export.h>
#include <SMLib/Video/Display.h>

namespace sml { 
namespace video {

	class SML_VIDEO_API MultiDisplay : private system::NoneCopyable {

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
			uint32_t GetNumberDisplays();

			//-----------------------------------------------------------------
			// Returning a reference to a display instance
			//-----------------------------------------------------------------
			Display& GetDisplayRef( const uint32_t &index ) const;



		private:
			
			//-----------------------------------------------------------------
			// Default constructor
			//-----------------------------------------------------------------
			MultiDisplay( );
			

			//-----------------------------------------------------------------
			// Conteiner for diaplys instances
			//-----------------------------------------------------------------
			std::map< uint32_t, Display > displays_;

			//-----------------------------------------------------------------
			// Adding a display instance to a container
			//-----------------------------------------------------------------
			void RegInstance( const uint32_t &index, const Display &regInst );
			
			void ClearDisplayInstances();

	}; // class DisplayAccess
} // namespace video
} // namespace sml
#endif // !SML_MULTI_DISPLAYS_H_
//---------------------------- End of file MultiDisplays.h --------------------