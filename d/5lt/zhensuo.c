// Room: /d/5lt/zhensuo.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "青蛙診所");
	set  ("long",  @LONG
這裏便是江湖醫生青蛙的診所了。柔和的燈光下，陶瓷地板清潔明
亮，搭配着牆角的幾叢文竹、龜背和君子蘭，入門就給人寧靜的感覺。
彌散着淡淡香氣的房間裏有幾扇玻璃門，裏屋隱隱傳來護士們的陣陣談
笑聲。門口擺放一張桌子，一個相貌清秀的年輕人正襟危坐翻看着厚厚
的書籍，一杯鐵觀音微微冒着熱氣。牆上沒有一般診所裏常見的錦旗獎
狀，只有門口一張廣告(guanggao）説明瞭此處的所用。
LONG);
	set("item_desc", ([
		"guanggao" : "本店出售以下藥品：
三黃寶蠟丸：\t一兩黃金
三清換質丹：\t一兩黃金
黑石玉洞丹：\t十兩黃金\n"
	]));
	set("exits",  ([  //sizeof()  ==  2
		"west"  :  __DIR__"sroad2",
		"up"    :  __DIR__"zhensuo2",
	]));
	set("objects",  ([
		__DIR__"npc/afrog": 1,
		__DIR__"npc/huoji": 1,
	]));
	set("no_fight", "1");
	set("coor/x", -140);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
}
