/*
    Modbus Tools

    Created: 2023
    Author: Serhii Marchuk, https://github.com/serhmarch

    Copyright (C) 2023  Serhii Marchuk

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#ifndef CLIENT_SCANNERTHREAD_H
#define CLIENT_SCANNERTHREAD_H

#include <QThread>

#include <client_global.h>

#include "client_scanner.h"

class mbClientScannerThread : public QThread
{
public:
    explicit mbClientScannerThread(mbClientScanner *scanner, QObject *parent = nullptr);
    ~mbClientScannerThread();

public:
    inline void stop() { m_ctrlRun = false; }
    void setSettings(const Modbus::Settings &settings);

protected:
    void run() override;

private Q_SLOTS:
    void slotBytesTx(const Modbus::Char *source, const uint8_t* buff, uint16_t size);
    void slotBytesRx(const Modbus::Char *source, const uint8_t* buff, uint16_t size);
    void slotAsciiTx(const Modbus::Char *source, const uint8_t* buff, uint16_t size);
    void slotAsciiRx(const Modbus::Char *source, const uint8_t* buff, uint16_t size);

private:
    void incStatTx();
    void incStatRx();

private:
    bool m_ctrlRun;

private:
    mbClientScanner *m_scanner;
    uint16_t m_unitStart;
    uint16_t m_unitEnd;
    mbClientScanner::Request_t m_request;
    Modbus::Settings m_settings;

private: // settings combination
    struct DivMod
    {
        quint16 div;
        quint16 mod;
    };

    typedef QList<DivMod> DivMods_t;
    typedef QStringList Names_t;
    typedef QList<QVariantList> ValuesList_t;

    DivMods_t    m_divMods   ;
    Names_t      m_names     ;
    ValuesList_t m_valuesList;
    quint32 m_combinationCount;
    quint32 m_combinationCountAll;
    quint32 m_statTx;
    quint32 m_statRx;
};

#endif // CLIENT_SCANNERTHREAD_H
