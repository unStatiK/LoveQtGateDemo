#include "customqtlib.h"
#include "wrapper.h"

extern "C" {
        CustomQtLib* newInstance() {
                return new CustomQtLib();
        }

        void CustomQtLib_init(CustomQtLib* v) {
                v->init();
        }

        char* CustomQtLib_get_version(CustomQtLib* v) {
            return v->get_version();
        }

        MetaInfoContainer CustomQtLib_get_meta_info(CustomQtLib* v) {
            MetaInfoContainer metaInfo;
            QMap<QString, QVariant> map;
            QSqlQuery q = v->select(QString("SELECT db_version, description from meta"), map);
            q.next();
            metaInfo.db_version = q.value(0).toInt();
            metaInfo.description = q.value(1).toString().toStdString().c_str();
            return metaInfo;
        }
}
