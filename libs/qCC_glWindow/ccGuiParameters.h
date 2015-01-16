//##########################################################################
//#                                                                        #
//#                            CLOUDCOMPARE                                #
//#                                                                        #
//#  This program is free software; you can redistribute it and/or modify  #
//#  it under the terms of the GNU General Public License as published by  #
//#  the Free Software Foundation; version 2 of the License.               #
//#                                                                        #
//#  This program is distributed in the hope that it will be useful,       #
//#  but WITHOUT ANY WARRANTY; without even the implied warranty of        #
//#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         #
//#  GNU General Public License for more details.                          #
//#                                                                        #
//#          COPYRIGHT: EDF R&D / TELECOM ParisTech (ENST-TSI)             #
//#                                                                        #
//##########################################################################

#ifndef GUI_PARAMETERS_HEADER
#define GUI_PARAMETERS_HEADER

//Qt
#include <QString>

//qCC_db
#include <ccColorTypes.h>

/***************************************************
				GUI parameters
***************************************************/

//! This class manages the persistent parameters (mostly for display)
/** Values of persistent parameters are stored by the system
	(either in the registry or in a separate file).
**/
class ccGui
{
public:

	//! GUI parameters
	struct ParamStruct
	{
		//! Light diffuse color (RGBA)
		ccColor::Rgbaf lightDiffuseColor;
		//! Light ambient color (RGBA)
		ccColor::Rgbaf lightAmbientColor;
		//! Light specular color (RGBA)
		ccColor::Rgbaf lightSpecularColor;

		//! Default mesh diffuse color (front)
		ccColor::Rgbaf meshFrontDiff;
		//! Default mesh diffuse color (back)
		ccColor::Rgbaf meshBackDiff;
		//! Default mesh specular color
		ccColor::Rgbaf meshSpecular;

		//! Default text color
		ccColor::Rgbub textDefaultCol;
		//! Default 3D points color
		ccColor::Rgbub pointsDefaultCol;
		//! Background color
		ccColor::Rgbub backgroundCol;
		//! Histogram background color
		ccColor::Rgbub histBackgroundCol;
		//! Labels background color
		ccColor::Rgbub labelBackgroundCol;
		//! Labels marker color
		ccColor::Rgbub labelMarkerCol;
		//! Bounding-boxes color
		ccColor::Rgbub bbDefaultCol;
		
		//! Use background gradient
		bool drawBackgroundGradient;
		//! Decimate meshes when moved
		bool decimateMeshOnMove;
		//! Decimate clouds when moved
		bool decimateCloudOnMove;
		//! Display cross in the middle of the screen
		bool displayCross;
		//! Whether to use VBOs for faster display
		bool useVBOs;

		//! Label marker size
		unsigned labelMarkerSize;

		//! Color scale option: show histogram next to color ramp
		bool colorScaleShowHistogram;
		//! Whether to use shader for color scale display (if available) or not
		bool colorScaleUseShader;
		//! Whether shader for color scale display is available or not
		bool colorScaleShaderSupported;
		//! Color scale ramp width (for display)
		unsigned colorScaleRampWidth;

		//! Default displayed font size
		unsigned defaultFontSize;
		//! Label font size
		unsigned labelFontSize;
		//! Displayed numbers precision
		unsigned displayedNumPrecision;
		//! Labels background opcaity
		unsigned labelOpacity;

		//! Default constructor
		ParamStruct();

		//! Resets parameters to default values
		void reset();

		//! Loads from persistent DB
		void fromPersistentSettings();

		//! Saves to persistent DB
		void toPersistentSettings() const;

		//! Returns whether a given parameter is already defined in persistent settings or not
		/** \param paramName the corresponding attribute name
		**/
		bool isInPersistentSettings(QString paramName) const;
	};

	//! Returns the stored values of each parameter.
	static const ParamStruct& Parameters();

	//! Sets GUI parameters
	static void Set(const ParamStruct& params);

	//! Release unique instance (if any)
	static void ReleaseInstance();

protected:

	//! Parameters set
	ParamStruct params;

};

#endif
