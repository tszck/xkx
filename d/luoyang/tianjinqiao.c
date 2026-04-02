// Room: /d/luoyang/tianjinqiao.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "天津曉月");
	set("long",  @LONG
天津橋是用鐵索連起無數大船而形成的一座浮橋。每當凌晨時分，
曉月還掛在天空，天津橋上的行人就熙熙攘攘車馬如流了，無怪乎唐代
詩人列希夷寫道“馬聲回合青雲外，人影動搖綠波里”，真是寫景如畫。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north" :  __DIR__"southgate",
		"south" :  __DIR__"road4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "luoyang");
	set("coor/x", -500);
	set("coor/y", -35);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
