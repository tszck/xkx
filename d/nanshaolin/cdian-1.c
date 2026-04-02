// Room: /d/nanshaolin/cdian-1.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "東側殿");
	set("long", @LONG
這裏是東側殿。房間四周懸掛着達摩祖師、觀音大士的畫像，以及
一些寺內元老的字畫。地下散亂地放着許多蒲團，木魚等。看來此處是
本派弟子打坐修行之所。幾位年輕僧人正肅容入定，看來已頗得禪宗三
昧。
LONG);
	set("exits", ([
		"west" : __DIR__"gchang-3",
	]));
	set("objects",([
		WEAPON_DIR+"stick/mugun" : 1,
	]));
	set("coor/x", 1840);
	set("coor/y", -6290);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

