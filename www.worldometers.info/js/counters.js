RTS_callbacks.register_init(function() {

	var _fadeout=200;
	var _fadein=150;

	//set callbacks for clicks on global start/global pause



	$('#global_pause').click(function() {
		RTS_callbacks.global_pause();
		$('#global_pause').hide();
		$('#global_start').show();
		
		$('#global_reset').addClass('rts_disabled');
		$('a.settype').each(function() {
			var $t=$(this);
			$t.after('<span class="settype_text">'+$t.text()+'</span>');
			$t.addClass('rts_disabled');
		});
		
		return false;
	});

	$('#global_start').click(function() {
		RTS_callbacks.global_start();
		$('#global_pause').show();
		$('#global_start').hide();

		$('#global_reset').removeClass('rts_disabled');
		$('.settype_text').remove();
		$('a.settype').removeClass('rts_disabled');
		return false;
	});

	var isreset=false;
	var types={};

	var find_closest_counter= function(el) {
		return $(el).closest("*:has(.rts-counter)").find(".rts-counter");
	};

	//getting starting type
	$('a.settype').each(function() {
		var $t=$(this);
		var rel=find_closest_counter($t).attr('rel').split('/');
		types[rel[0]]=(rel[1] ? rel[1] : 'this_year');
	});


	$('a.settype').click(function() {
		var $t=$(this);
		var $counter=find_closest_counter($t);
		var key=$counter.attr('rel').split('/')[0];
		
		
		var switchto=function(type,str)  {
			$t.fadeTo(_fadeout,0,function() {
				$t.html(str);
				$t.fadeTo(_fadein,1);
			});
			$counter.fadeTo(_fadeout,0,function() {
				types[key]=type;
				RTS_callbacks.counter_settype(key,type);
				$counter.fadeTo(_fadein,1);
			});
		};
		
		if (types[key]=='this_year') 
			switchto('today','today');
		else
			switchto('this_year','this year');
		isreset=false;
		return false;
	});

	$('#global_reset').click(function() {
		RTS_callbacks.global_action('reset');
		RTS_callbacks.global_settype('reset');
		$('a.settype').html('reset');
		$('tr.time_since_reset').show();
		isreset=true;
		return false;
	});







});