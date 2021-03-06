#include "musicxmqueryartistlistrequest.h"

#define REFER_URL   "UWhHVHk0M0QwSEJ5djJjeVZmaTNqL0R3amVKTnA0anJtdUdvck9MeExYZStnaHpT"

MusicXMQueryArtistListRequest::MusicXMQueryArtistListRequest(QObject *parent)
    : MusicQueryArtistListRequest(parent)
{
    m_pageSize = 100;
    m_queryServer = QUERY_XM_INTERFACE;
}

void MusicXMQueryArtistListRequest::startToPage(int offset)
{
    if(!m_manager)
    {
        return;
    }

    TTK_LOGGER_INFO(QString("%1 startToPage %2").arg(getClassName()).arg(offset));

    deleteAll();
    QString catId = "class=1&type=1";
    const QStringList &dds = m_searchText.split(TTK_STR_SPLITER);
    if(dds.count() == 2)
    {
        catId = dds[0];
        if(catId.isEmpty())
        {
            catId = "class=1&type=1";
        }
    }
    m_totalSize = DEFAULT_LEVEL_HIGHER;

    QNetworkRequest request;
    request.setUrl(MusicUtils::Algorithm::mdII(XM_ARTIST_LIST_URL, false).arg(catId).arg(offset).arg(m_pageSize));
    request.setRawHeader("Referer", MusicUtils::Algorithm::mdII(REFER_URL, false).toUtf8());
    request.setRawHeader("User-Agent", MusicUtils::Algorithm::mdII(XM_UA_URL, ALG_UA_KEY, false).toUtf8());
    MusicObject::setSslConfiguration(&request);

    m_reply = m_manager->get(request);
    connect(m_reply, SIGNAL(finished()), SLOT(downLoadFinished()));
    connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)), SLOT(replyError(QNetworkReply::NetworkError)));
}

void MusicXMQueryArtistListRequest::startToSearch(const QString &artistlist)
{
    m_searchText = artistlist;
    m_searchText.replace("n", "&");
    startToPage(0);
}

void MusicXMQueryArtistListRequest::downLoadFinished()
{
    TTK_LOGGER_INFO(QString("%1 downLoadFinished").arg(getClassName()));

    Q_EMIT clearAllItems();
    m_musicSongInfos.clear();
    setNetworkAbort(false);

    if(m_reply && m_reply->error() == QNetworkReply::NoError)
    {
        QJson::Parser parser;
        bool ok;
        const QVariant &data = parser.parse(m_reply->readAll(), &ok);
        if(ok)
        {
            QVariantMap value = data.toMap();
            if(value.contains("data") && value["state"].toInt() == 0)
            {
                value = value["data"].toMap();
                const QVariantList &datas = value["artists"].toList();
                for(const QVariant &var : qAsConst(datas))
                {
                    if(var.isNull())
                    {
                        continue;
                    }

                    value = var.toMap();
                    TTK_NETWORK_QUERY_CHECK();

                    MusicResultsItem info;
                    info.m_id = value["artist_id"].toString();
                    info.m_name = value["name"].toString();
                    Q_EMIT createArtistListItem(info);
                }
            }
        }
    }

//    Q_EMIT downLoadDataChanged(QString());
    deleteAll();
}
