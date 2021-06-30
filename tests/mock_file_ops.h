/*
 * Copyright (C) 2021 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef MULTIPASS_MOCK_CONST_FILE_OPS_H
#define MULTIPASS_MOCK_CONST_FILE_OPS_H

#include "common.h"
#include "mock_singleton_helpers.h"

#include <multipass/file_ops.h>

namespace multipass::test
{
class MockFileOps : public FileOps
{
public:
    using FileOps::FileOps;

    MOCK_CONST_METHOD1(isReadable, bool(QDir&));
    MOCK_CONST_METHOD2(rmdir, bool(QDir&, const QString& dirName));
    MOCK_CONST_METHOD2(open, bool(QFile&, QIODevice::OpenMode));
    MOCK_CONST_METHOD1(is_open, bool(const QFile&));
    MOCK_CONST_METHOD3(read, qint64(QFile&, char*, qint64));
    MOCK_CONST_METHOD1(read_line, QString(QTextStream&));
    MOCK_CONST_METHOD1(remove, bool(QFile&));
    MOCK_CONST_METHOD2(rename, bool(QFile&, const QString& newName));
    MOCK_CONST_METHOD2(resize, bool(QFile&, qint64 sz));
    MOCK_CONST_METHOD2(seek, bool(QFile&, qint64 pos));
    MOCK_CONST_METHOD2(setPermissions, bool(QFile&, QFileDevice::Permissions));
    MOCK_CONST_METHOD3(write, qint64(QFile&, const char*, qint64));
    MOCK_CONST_METHOD2(write, qint64(QFile&, const QByteArray&));

    MP_MOCK_SINGLETON_BOILERPLATE(MockFileOps, FileOps);
};
} // namespace multipass::test

#endif // MULTIPASS_MOCK_FILE_OPS_H
