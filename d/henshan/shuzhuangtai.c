// Room: /d/henshan/shuzhuangtai.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "梳妝枱");
        set("long", @LONG
藏經殿有一泓碧泉如鏡，向稱美容泉。相傳為南陳後主妃在此避亂
時，對碧水照容顏梳妝打扮的地方。殿前勝蹟有靈日，昔時夜間常見飛
光，或如繁星點點，或若萬螢亂飛，煞是壯觀。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "north"   : __DIR__"cangjingdian",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -340);
	set("coor/y", -1020);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
