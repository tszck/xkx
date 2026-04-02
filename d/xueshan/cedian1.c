//      cedian1.c 側殿
#include <room.h>
inherit ROOM;

void create()
{
        set("short","側殿");
        set("long",@LONG
這裏是雪山寺的東側殿。殿內有神態各異的十八羅漢塑像，金旒玉
鑲，很是莊嚴。
LONG );
        set("exits",([
                "up"   : __DIR__"zoulang1",
                "west" : __DIR__"dadian",
        ]));
        set("objects",([
                CLASS_D("xueshan")+"/jiamu" : 1,
                __DIR__"npc/xiang-ke"       : 3,
        ]));
	set("coor/x", -69990);
	set("coor/y", -19890);
	set("coor/z", 120);
	setup();
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam=(mapping)me->query("family");
        if( (!myfam || myfam["family_name"] !="雪山寺") && dir=="up"
        && objectp(present ("jiamu huofo", environment(me))))
                return notify_fail("嘉木活佛説道: 你非雪山寺弟子, 不能入內。\n");
        return ::valid_leave(me,dir);
}
