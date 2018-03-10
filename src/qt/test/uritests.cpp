#include "uritests.h"

#include "guiutil.h"
#include "walletmodel.h"

#include <QUrl>

void URITests::uriTests()
{
    SendCoinsRecipient rv;
    QUrl uri;
    uri.setUrl(QString("artiqox:GM5RxyuyWw5wUCnkUXteFuMpu6jieCkVSt?req-dontexist="));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("artiqox:GM5RxyuyWw5wUCnkUXteFuMpu6jieCkVSt?dontexist="));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("GM5RxyuyWw5wUCnkUXteFuMpu6jieCkVSt"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("artiqox:GM5RxyuyWw5wUCnkUXteFuMpu6jieCkVSt?label=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("GM5RxyuyWw5wUCnkUXteFuMpu6jieCkVSt"));
    QVERIFY(rv.label == QString("Wikipedia Example Address"));
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("artiqox:GM5RxyuyWw5wUCnkUXteFuMpu6jieCkVSt?amount=0.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("GM5RxyuyWw5wUCnkUXteFuMpu6jieCkVSt"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100000);

    uri.setUrl(QString("artiqox:GM5RxyuyWw5wUCnkUXteFuMpu6jieCkVSt?amount=1.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("GM5RxyuyWw5wUCnkUXteFuMpu6jieCkVSt"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100100000);

    uri.setUrl(QString("artiqox:GM5RxyuyWw5wUCnkUXteFuMpu6jieCkVSt?amount=100&label=Wikipedia Example"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("GM5RxyuyWw5wUCnkUXteFuMpu6jieCkVSt"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Wikipedia Example"));

    uri.setUrl(QString("artiqox:GM5RxyuyWw5wUCnkUXteFuMpu6jieCkVSt?message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("GM5RxyuyWw5wUCnkUXteFuMpu6jieCkVSt"));
    QVERIFY(rv.label == QString());

    QVERIFY(GUIUtil::parseBitcoinURI("artiqox://GM5RxyuyWw5wUCnkUXteFuMpu6jieCkVSt?message=Wikipedia Example Address", &rv));
    QVERIFY(rv.address == QString("GM5RxyuyWw5wUCnkUXteFuMpu6jieCkVSt"));
    QVERIFY(rv.label == QString());

    uri.setUrl(QString("artiqox:GM5RxyuyWw5wUCnkUXteFuMpu6jieCkVSt?req-message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("artiqox:GM5RxyuyWw5wUCnkUXteFuMpu6jieCkVSt?amount=1,000&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("artiqox:GM5RxyuyWw5wUCnkUXteFuMpu6jieCkVSt?amount=1,000.0&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));
}
