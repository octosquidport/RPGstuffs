extends Node

onready var backColorNode = $BackColor

func _ready():
	backColorNode.rect_size = Globe.scrnDim
	
	pass
