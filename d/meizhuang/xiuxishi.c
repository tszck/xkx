// /d/meizhuang/xiuxishi.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "休息室");
	set("long", @LONG
這裏是梅莊弟子練功勞累的時候，休息的地方，這裏經常可以聽到
如雷的鼾聲，這裏簡單的放着幾張墊子，幾牀棉被，幾個枕頭，而且梅
莊弟子雖然經常打掃這裏，但這裏仍然凌亂不堪，很多梅莊弟子一進這
裏，倒頭便睡，顯是過於疲勞的緣故。 
LONG
	);
	set("sleep_room", "yes");
	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"zoulang2",
	]));
	set("no_fight", "yes");
	set("no_clean_up", 0);

	set("coor/x", 3510);
	set("coor/y", -1370);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
