/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef MU_ENGRAVING_TYPESCONV_H
#define MU_ENGRAVING_TYPESCONV_H

#include <QString>
#include "types.h"

namespace mu::engraving {
class TConv
{
public:
    TConv() = default;

    static QString toUserName(NoteHeadType v);
    static QString toXml(NoteHeadType v);
    static NoteHeadType fromXml(const QString& tag, NoteHeadType def);
    static QString toUserName(NoteHeadScheme v);
    static QString toXml(NoteHeadScheme v);
    static NoteHeadScheme fromXml(const QString& tag, NoteHeadScheme def);
    static QString toUserName(NoteHeadGroup v);
    static QString toXml(NoteHeadGroup v);
    static NoteHeadGroup fromXml(const QString& tag, NoteHeadGroup def);

    static QString toUserName(ClefType v);
    static QString toXml(ClefType v);
    static ClefType fromXml(const QString& tag, ClefType def);
};
}

#endif // MU_ENGRAVING_TYPESCONV_H