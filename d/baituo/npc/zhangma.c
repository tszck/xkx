// zhangma.c
// Last Modified by Winder on May. 15 2001

inherit NPC;
string inquiry_hua();

void create()
{
	set_name("張媽", ({ "zhang ma","zhang","ma"}) );
	set("gender", "女性" );
	set("age", 50);
	set("long", "一個歷經滄桑的老婆婆。\n");
	set("shen_type", 1);
	set("combat_exp", 500);
	set("str", 16);
	set("dex", 17);
	set("con", 17);
	set("int", 18);
	set("attitude", "friendly");
	set("chat_chance",60);
	set("chat_msg",({
		"張媽唸叨着：我苦命的『金花』喲，你現在在那裏喲￣\n",
		"張媽暗暗抹了把眼淚。\n",
		"張媽獨自説道：我的『金花』呀，你怎能撇下我自個兒走了￣\n"
	}) );
	set("inquiry",([
		"金花" : (: inquiry_hua :),
	]) );
	set_temp("shoe",1);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

string inquiry_hua()
{
	object me=this_player();
	object obn;
	message_vision("張媽説道：這位"+ RANK_D->query_respect(me)+"，『金花』是我的親閨女，\n甭提多孝順了！\n可惜去年上山割草就一去不會，也不知是死是活。唉！\n", me );
	if(query_temp("shoe")==0)
	{
		message_vision("張媽又説道：這位"+ RANK_D->query_respect(me)+"，我已經託\n人去尋找了，也不知道怎麼樣了。\n",me);
		return "";
	}
	message_vision("張媽又説道：這位"+ RANK_D->query_respect(me)+"，我這裏有她落在草叢裏的一隻「繡花鞋」，\n你要是找到『金花』，就把鞋交給她，她會明白的。\n我女兒『金花』的命運，就託給你了。\n" , me);
	obn=new("/d/baituo/obj/shoe");
	obn->move(me);
	set_temp("shoe",0);
	return "張媽從懷裏摸出一隻「繡花鞋」，交給你。\n";
}
