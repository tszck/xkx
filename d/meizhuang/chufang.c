// /d/meizhuang/chufang.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "廚房");
	set("long", @LONG
你順着香味走到了梅莊的廚房，一位廚師正站在竈臺後面笑眯眯的
看着你，他手上拿着一柄鐵勺，用力的把鍋裏煮着的一大堆食物攪勻，
梅莊的弟子們如果餓了，就到這裏來問這位廚師能不能喫飯，一般來説，
他們都不會遭到拒絕的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"zoulang3",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/chushi" : 1,
	]));

	set("coor/x", 3500);
	set("coor/y", -1350);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
