#ifndef MusicDownloadTagDataRequest_H
#define MusicDownloadTagDataRequest_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (C) 2015 - 2021 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

#include "musicsonginfo.h"
#include "musicdownloaddatarequest.h"

/*! @brief The class of downloading the type of data by custom tags.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_NETWORK_EXPORT MusicDownloadTagDataRequest : public MusicDownloadDataRequest
{
    Q_OBJECT
    TTK_DECLARE_MODULE(MusicDownloadTagDataRequest)
public:
    /*!
     * Object contsructor provide download URL\ save local path and download type.
     */
    MusicDownloadTagDataRequest(const QString &url, const QString &save, MusicObject::DownloadType type, QObject *parent = nullptr);

    /*!
     * Set custom tags.
     */
    void setSongInfo(const MusicSongInfo &info);
    /*!
     * Start to download data.
     */
    virtual void startToDownload() override;

Q_SIGNALS:
    /*!
     * Modify tag finished.
     */
    void finished();

public Q_SLOTS:
    /*!
     * Download data from net finished.
     */
    virtual void downLoadFinished() override;
    /*!
     * Send download byte data from net.
     */
    void downLoadFinished(const QByteArray &data);

protected:
    MusicSongInfo m_musicInfo;

};

#endif // MusicDownloadTagDataRequest_H
