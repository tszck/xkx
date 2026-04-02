// Room: /d/henshan/shuiliandong.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "水簾洞");
        set("long", @LONG
水簾洞在紫蓋峯下，在吐霧和香爐兩峯之間。紫蓋峯之水經山澗匯
入紫蓋仙洞中，深不可測，水滿則溢，飛瀑高二十餘丈，數疊垂簾，飄
泄而下，蔚為壯觀。明張居正詩曰:  "誤疑瀛海翻瓊波，莫擬銀河倒碧
流，自是湘妃深隱處，水晶簾掛五雲頭。" 以讚歎這衡山大四絕之一的
 "水簾洞之奇" 。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "westdown"    : __DIR__"shanlu12",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "henshan");
	set("coor/x", -280);
	set("coor/y", -1080);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
