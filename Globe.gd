extends Node # Autoload scripts must extend Node

const ASDF = [27, 33.75]
#onready var scrnDim = get_viewport().get_visible_rect().size setget ,get_screen_dim
onready var scrnDim = get_viewport().size

func _ready():
	# Default Background Color # _enter_tree() and _init() work too
	VisualServer.set_default_clear_color( Color.whitesmoke )

func get_screen_dim() -> Vector2:
	return scrnDim
	
#func _process(delta):
#	pass
