#ifndef QDESENCODE_H
#define QDESENCODE_H

#include <QString>
#include <string>
QString HexArrayToString(int * a);
QString EncodeMain(QString mingwen,QString q_key);
QString DecodeMain(QString miwen,QString q_key2);
void Decode(int *str,int *keychar);
void Encode(int *str,int *keychar);
void keyBuild(int *keychar);
void StrtoBin(int *midkey,int *keychar);
void keyCreate(int *midkey2,int movebit,int i);
void EncodeData(int *lData,int *rData,int *srt);
void F(int *rData,int *key);
void Expand(int *rData,int *rDataP);
void ExchangeS(int *rDataP,int *rData);
void ExchangeP(int *rData);
void FillBin(int *rData,int n,int s);
void DecodeData(int *str,int *lData,int *rData);

#endif
