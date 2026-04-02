// Room: /d/henshan/zhurongfeng.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "祝融峯");
        set("long", @LONG
 "祝融峯之高" 爲衡山大四絕之首。在此俯瞰羣峯，盡收眼底。東
望湘江，南及五嶺，北瞰洞庭，西視雪山。杜甫望嶽詩中有 "祝融五峯
尊，峯峯次低昂。" 韓愈亦以 "祝融萬丈拔地起，欲見不見輕煙裏" 極
言其高。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "eastdown"   : __DIR__"zhurongdian",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -320);
	set("coor/y", -990);
	set("coor/z", 60);
	setup();
        replace_program(ROOM);
}
