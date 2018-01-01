/*
 *  Copyright (C) 2017 KeePassXC Team
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 or (at your option)
 *  version 3 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KEEPASSX_ARGON2KDF_H
#define KEEPASSX_ARGON2KDF_H

#include "Kdf.h"

class Argon2Kdf : public Kdf {
public:
    Argon2Kdf();

    bool transform(const QByteArray& raw, QByteArray& result) const override;
    QSharedPointer<Kdf> clone() const override;

    quint32 memory() const;
    bool setMemory(quint32 memory_kb);
    quint32 parallelism() const;
    bool setParallelism(quint32 threads);

protected:
    int benchmarkImpl(int msec) const override;

    quint32 m_memory;
    quint32 m_parallelism;

private:
    static bool transformKeyRaw(const QByteArray& key,
                                const QByteArray& seed,
                                int rounds,
                                quint32 memory,
                                quint32 parallelism,
                                QByteArray& result) Q_REQUIRED_RESULT;
};

#endif // KEEPASSX_ARGON2KDF_H
