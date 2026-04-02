// Room: /d/yanziwu/taihua.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "太湖");
	set("long",@LONG
綠衫少女臉帶微笑，如春花般嬌癡無瑕。兩手劃槳，不時採摘蓮實
戲耍。口中漫聲唱道:  "菡萏香連十頃陂，小姑貪戲採蓮遲。晚來弄水
船頭灘，笑脫紅裙裹鴨兒。" 碧玉般湖面淡淡彌散着輕柔的曲調。
LONG );
	set("outdoors", "yanziwu");
	set("no_clean_up", 0);
	set("coor/x", 810);
	set("coor/y", -1200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
