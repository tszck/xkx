// Room: /d/baituo/yaofang.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","藥房");
	set("long", @LONG
這裏是間藥房，靠牆放着一隻大藥櫃。屋子裏有張桌子，上邊擺滿
了煉藥用的瓶瓶罐罐。其中一個藥瓶(bottle)裏只裝了清水。煉藥師是
位小姑娘，正在那裏發呆，不知在想什麼。北面是氣派的長廊。
LONG	);
	set("exits",([
		"north" : __DIR__"changlang",
	]));
	set("no_fight", 1);
	set("item_desc",([
		"bottle" : "藥罐上貼着標籤：『蛇膽膏』，乃珍貴補品，生精補氣，效果奇佳。\n",
	]));
	set("objects",([
//		__DIR__"obj/wan" :1,
		__DIR__"npc/xiaoqing" : 1,
	]));
	set("coor/x", -50020);
	set("coor/y", 20030);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
