// Room: /yangzhou/xianguopu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","彭記鮮果鋪");
	set("long",@LONG
人說彭記是一家揚州城的老字號，揚州城內的大戶人家採買鮮果都
是來此，因而店內人來人往，極爲熱鬧，小二忙來忙去招呼着買家。門
楣上有一燙金匾額，架上的各色鮮果飄出的清香沁人心脾，令人垂涎欲
滴。邊上的躺椅上有個胖子，似乎是帳房先生。
LONG );
	set("exits", ([
		"west" : __DIR__"caiyidongjie",
	]));
	set("objects", ([
		__DIR__"npc/pengbaoxian" : 1,
	]));
	set("coor/x", 70);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}