// Room: /d/wizard/wizard_room.c
// Last modified by winder 2002/10/18

inherit ROOM;

void create()
{
	set("short", "巫師休息室");
	set("long", @LONG
這裏就是「俠客行一百」巫師的休息所在，剛粉刷過的四周牆壁上
光禿禿的什麼都沒有，屋子的正中央放着一張楠木桌，上面擺着一本巫
師留言簿(board)。
LONG );

	set("exits", ([ /* sizeof() == 1 */
		"up"    : __DIR__"meeting_room",
	 	"down"  : __DIR__"guest_room",
	]));
	set("no_fight", "1");
	set("no_clean_up", 0);
	set("coor/x",-1);
	set("coor/y",1);
	set("coor/z",10);
	setup();

	call_other("/clone/board/wiz_b", "???");
	replace_program(ROOM);
}
