#ifndef MUSICSONGINFO_H
#define MUSICSONGINFO_H

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

#include <QVariant>

#include "tagwrapper.h"
#include "musicglobaldefine.h"

/*! @brief The class of the music song info.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_CORE_EXPORT MusicSongInfo
{
    TTK_DECLARE_MODULE(MusicSongInfo)
public:
    /*!
     * Object contsructor.
     */
    MusicSongInfo();
    /*!
     * Object contsructor.
     */
    explicit MusicSongInfo(const QString &file);

    /*!
     * Read music file to anaylsis.
     */
    bool read();
    /*!
     * Read music file to anaylsis.
     */
    bool read(const QString &file);
    /*!
     * Save music tags to music file.
     */
    bool save();

    /*!
     * Read music decoder name.
     */
    QString getDecoder() const;
    /*!
     * Read music file path.
     */
    QString getFilePath() const;
    /*!
     * Get artist name.
     */
    QString getArtist() const;
    /*!
     * Get song title.
     */
    QString getTitle() const;
    /*!
     * Get song album.
     */
    QString getAlbum() const;
    /*!
     * Get song comment.
     */
    QString getComment() const;
    /*!
     * Get song year.
     */
    QString getYear() const;
    /*!
     * Get song track number.
     */
    QString getTrackNum() const;
    /*!
     * Get song genre.
     */
    QString getGenre() const;
    /*!
     * Get song album artist.
     */
    QString getAlbumArtist() const;
    /*!
     * Get song composer.
     */
    QString getComposer() const;
    /*!
     * Get song channel.
     */
    QString getChannel() const;
    /*!
     * Get song file path.
     */
    QString getURL() const;
    /*!
     * Set artist name.
     */
    void setArtist(const QString &artist);
    /*!
     * Set song title.
     */
    void setTitle(const QString &title);
    /*!
     * Set song album.
     */
    void setAlbum(const QString &album);
    /*!
     * Set song comment.
     */
    void setComment(const QString &comment);
    /*!
     * Set song year.
     */
    void setYear(const QString &year);
    /*!
     * Set song track number.
     */
    void setTrackNum(const QString &track);
    /*!
     * Set song genre.
     */
    void setGenre(const QString &genre);
    /*!
     * Set song image cover artist.
     */
    void setCover(const QPixmap &pix);
    /*!
     * Set song image cover artist.
     */
    void setCover(const QByteArray &data);
    /*!
     * Get song image cover artist.
     */
    QPixmap getCover() const;
    /*!
     * Get song sample rate.
     */
    QString getSampleRate() const;
    /*!
     * Get song format.
     */
    QString getFormat() const;
    /*!
     * Get song mode.
     */
    QString getMode() const;
    /*!
     * Get song bitrate.
     */
    QString getBitrate() const;
    /*!
     * Get song time length.
     */
    QString getLengthString() const;

protected:
    /*!
     * Find legal data string.
     */
    QString findLegalDataString(TagWrapper::Type type) const;
    /*!
     * Find current pluin store path.
     */
    QString findPluginPath() const;
    /*!
     * Read other taglib not by plugin.
     */
    bool readInformation();
    /*!
     * Save other taglib not by plugin.
     */
    bool saveInformation();

    QString m_filePath;
    QMap<TagWrapper::Type, QVariant> m_parameters;

};

#endif // MUSICSONGINFO_H
