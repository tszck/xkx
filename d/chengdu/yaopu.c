// Room: yaodian.c
// Date: Feb.14 1998 by Java
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;
void create()
{
	set("short", "濟世堂");
	set("long", @LONG
濟世堂藥店賣很多中原買不到的藥。託唐門的福，生意一直都很好。
一走進這家藥店，就聞到一股股濃烈刺鼻的藥味。你正奇怪藥店夥計怎
麼能忍受，就看到藥店裏還有一些人正拿奇怪的眼光看你。他們的腰間
鼓鼓囊囊的，顯然不是好惹的。
LONG	);
	set("objects", ([
		__DIR__"npc/huoji1" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"xijie1",
	]));
	set("coor/x", -8070);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
