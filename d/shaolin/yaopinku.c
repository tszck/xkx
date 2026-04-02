// Room: /d/shaolin/yaopinku.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "藥品庫");
	set("long", @LONG
這裏是全寺僧侶領用藥品的地方。房間裏弭漫着股濃濃
的藥味。靠牆是一排排高及房頂的藥櫃，每個藥櫃都由上百
個裝藥的小抽屜，上面貼滿了密密麻麻的各種草頭藥名。東
首牆邊放着個巨大的暗紅色杉木藥櫃，上面貼着個蓋有方丈
印籤的大封條。一位中年僧人正來回忙碌着稱量藥品，熬藥
煎湯。
LONG );
	set("exits", ([
		"south" : __DIR__"fangjuku",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/dao-xiang2" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 30);
	set("coor/y", 920);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}