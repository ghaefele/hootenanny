/*
 * This file is part of Hootenanny.
 *
 * Hootenanny is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * --------------------------------------------------------------------
 *
 * The following copyright notices are generated automatically. If you
 * have a new notice to add, please use the format:
 * " * @copyright Copyright ..."
 * This will properly maintain the copyright information. DigitalGlobe
 * copyrights will be updated automatically.
 *
 * @copyright Copyright (C) 2014 DigitalGlobe (http://www.digitalglobe.com/)
 */

//
// NFDD Conversion - With "English" output
//

// For the OSM+ to NFDD translation
hoot.require('tds40')
hoot.require('tds40_schema')
hoot.require('tds40_rules')
hoot.require('fcode_common')

// The main translation functions
hoot.require('etds')
hoot.require('etds_rules')

hoot.require('config')
hoot.require('translate')

// Create the output Schema - This is not used here. We _do_ use it in the etds functions but
// we don't need to expose it to the main Hoot program
function getDbSchema()
{
     return tds.getDbSchema();
}

// Get raw schema directly from plugins/schema
function getRawDbSchema()
{
     return tds.schema.getDbSchema();
}


// IMPORT
// translateAttributes - Normally takes 'attrs' and returns OSM 'tags'.  This version
//    converts OSM+ tags to NFDD "English" Attributes
//
// This can be called via the following for testing:
// hoot --convert -D "convert.ops=hoot::TranslationOp"  \ 
//      -D translation.script=$HOOT_HOME/translations/OSM_to_englishTDS.js <input>.osm <output>.osm
//
function translateAttributes(attrs, layerName, geometryType)
{
    // We use the temp var because etds.toEnglish returns "attrs" and "tableName"
    var output = etds.toEnglish(attrs,'',geometryType);

    // Make sure the returned value isn't NULL. This does occur
    if (output)
    {
        return output.attrs;
    }
    else
    {
        return null;
    }
} // End of Translate Attributes


// EXPORT
// translateToOgr - takes 'tags' + geometry and returns 'attrs' + tableName
//    This version converts OSM+ tags to NFDD "English" attributes
function translateToOgr(tags, elementType, geometryType)
{
        return etds.toEnglish(tags, elementType, geometryType)
} // End of translateToOgr





