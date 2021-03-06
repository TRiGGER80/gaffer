//////////////////////////////////////////////////////////////////////////
//  
//  Copyright (c) 2012, John Haddon. All rights reserved.
//  Copyright (c) 2013, Image Engine Design Inc. All rights reserved.
//  
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are
//  met:
//  
//      * Redistributions of source code must retain the above
//        copyright notice, this list of conditions and the following
//        disclaimer.
//  
//      * Redistributions in binary form must reproduce the above
//        copyright notice, this list of conditions and the following
//        disclaimer in the documentation and/or other materials provided with
//        the distribution.
//  
//      * Neither the name of John Haddon nor the names of
//        any other contributors to this software may be used to endorse or
//        promote products derived from this software without specific prior
//        written permission.
//  
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
//  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
//  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
//  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
//  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//  
//////////////////////////////////////////////////////////////////////////

#ifndef GAFFERIMAGEUI_IMAGEVIEW_H
#define GAFFERIMAGEUI_IMAGEVIEW_H

#include "GafferUI/View.h"

#include "GafferImage/ImagePlug.h"
#include "GafferImage/ImageStats.h"

#include "GafferImageUI/TypeIds.h"

namespace GafferImageUI
{

class ImageView : public GafferUI::View
{

	public :

		ImageView( const std::string &name = defaultName<ImageView>() );
		virtual ~ImageView();

		IE_CORE_DECLARERUNTIMETYPEDEXTENSION( GafferImageUI::ImageView, ImageViewTypeId, GafferUI::View );
	
	protected :

		/// This constructor is for classes which derive from ImageView, but
		/// don't necessarily accept an ImagePlug. Instead they should create
		/// a preprocessor node that accepts the input plug and outputs an
		/// image plug, and enable it using setPreprocessor().
		ImageView( const std::string &name, Gaffer::PlugPtr input );

		virtual void update();
		
		GafferImage::ImageStats *imageStatsNode();
		const GafferImage::ImageStats *imageStatsNode() const;
		
		static ViewDescription<ImageView> g_viewDescription;

	private:

		int m_colorMask;
		Imath::V2f m_mousePos;
};

IE_CORE_DECLAREPTR( ImageView );

} // namespace GafferImageUI

#endif // GAFFERIMAGEUI_IMAGEVIEW_H
