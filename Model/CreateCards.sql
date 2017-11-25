-- ============================================================
--   Database name:     numkinch
--   DBMS name:         SQLite
-- ============================================================

-- ============================================================
--   Table: room
-- ============================================================
CREATE TABLE room
(
    id_room			INT         PRIMARY KEY NOT NULL AUTO_INCREMENT,
    name            VARCHAR(255)            NOT NULL,
    description     VARCHAR(255)            NOT NULL,
    entityPath      VARCHAR(255)            NOT NULL,
    visited         INT                     NOT NULL,
    onBoard         INT                     NOT NULL,
    type            INT                     NOT NULL,
    CONSTRAINT pk_room PRIMARY KEY (id_room)
);

-- ============================================================
--   Table: player
-- ============================================================
CREATE TABLE player
(
    id_player	INT	      	    NOT NULL,
    race		VARCHAR(255)    NOT NULL,
    class       VARCHAR(255)    NOT NULL,
    attack      INT,
    maxAttack   INT,
    defense     INT,
    maxDefense  INT,
    agility     INT,
    maxAgility  INT,
    life        INT,
    maxLife     INT,
    CONSTRAINT pk_player PRIMARY KEY (id_player)
);

-- ============================================================
--   Table: monster
-- ============================================================
CREATE TABLE monster
(
    id_monster  INT NOT NULL,
    attack		INT NOT NULL,
    defense     INT NOT NULL,
    life        INT NOT NULL,
    isBoss      INT NOT NULL,
    CONSTRAINT pk_monster PRIMARY KEY (id_monster)
);

-- ============================================================
--   Table: trap
-- ============================================================
CREATE TABLE trap
(
    id_trap     INT NOT NULL,
    targetSkill	INT NOT NULL,
    malus		INT ,
    CONSTRAINT pk_trap PRIMARY KEY (id_trap)
);

-- ============================================================
--   Table: treasure
-- ============================================================
CREATE TABLE treasure
(
    id_treasure	INT NOT NULL,
    targetSkill INT	NOT NULL,
    bonus		INT NOT NULL,
    CONSTRAINT pk_treasure PRIMARY KEY (id_treasure)
);

-- ============================================================
--   Table : comporter
-- ============================================================
CREATE TABLE comporter
(
    id_recette				INT 		NOT NULL,
    id_ingredient			INT 		NOT NULL,
    valeur_quantite			INT(6)		NOT NULL,
    unite_quantite			VARCHAR(100)NOT NULL,
    CONSTRAINT pk_comporter PRIMARY KEY (id_recette, id_ingredient)
);

-- ============================================================
--   Table : ingredient
-- ============================================================
CREATE TABLE ingredient
(
    id_ingredient			INT 		NOT NULL AUTO_INCREMENT,
    nom_ingredient			VARCHAR(100)NOT NULL UNIQUE,
    CONSTRAINT pk_ingredient PRIMARY KEY (id_ingredient)
);

-- ============================================================
--   Table : posseder
-- ============================================================
CREATE TABLE posseder
(
    id_caracteristique		INT 		NOT NULL,
    id_ingredient			INT 		NOT NULL,
    valeur_numerique 		INT(4)		NOT NULL,
    unite_nutritionnelle	VARCHAR(100)NOT NULL,
    CONSTRAINT pk_posseder PRIMARY KEY (id_caracteristique, id_ingredient)
);

-- ============================================================
--   Table : caracteristique_nutri
-- ============================================================
CREATE TABLE caracteristique_nutri
(
    id_caracteristique		INT 		NOT NULL AUTO_INCREMENT,
    nom_caracteristique		VARCHAR(30)	NOT NULL UNIQUE,
    CONSTRAINT pk_caracteristique_nutri PRIMARY KEY (id_caracteristique)
);

-- ============================================================
--   Table : noter
-- ============================================================
CREATE TABLE noter
(
    id_internaute			INT 		NOT NULL,
    id_description			INT    		NOT NULL,
    note 					INT(1)		NOT NULL,
    CONSTRAINT pk_noter PRIMARY KEY (id_internaute, id_description)
);

-- ============================================================
--   Table : description
-- ============================================================
CREATE TABLE description
(
    id_description			INT    		NOT NULL AUTO_INCREMENT,
    texte_description		LONGTEXT	NOT NULL,
    date_debut_validite		DATE 		NOT NULL,
    date_fin_validite		DATE 		,
    id_internaute			INT 		NOT NULL,
    id_recette				INT   		NOT NULL,
    CONSTRAINT pk_description PRIMARY KEY (id_description)
);

-- ============================================================
--   Table : commentaire
-- ============================================================
CREATE TABLE commentaire
(
    id_commentaire			INT    		NOT NULL AUTO_INCREMENT,
    texte_commentaire		LONGTEXT	NOT NULL,
    id_internaute			INT 		NOT NULL,
    id_description			INT    		NOT NULL,
    CONSTRAINT pk_commentaire PRIMARY KEY (id_commentaire)
);

-- ============================================================
--   Table : internaute
-- ============================================================
CREATE TABLE internaute
(
    id_internaute			INT    		NOT NULL AUTO_INCREMENT,
    pseudo          		VARCHAR(100)NOT NULL UNIQUE,
    CONSTRAINT pk_internaute PRIMARY KEY (id_internaute)
);

ALTER TABLE menu
    add CONSTRAINT fk1_menu FOREIGN KEY (id_internaute)
       REFERENCES internaute (id_internaute)
       ON DELETE CASCADE;

ALTER TABLE description
    add CONSTRAINT fk1_description FOREIGN KEY (id_internaute)
    	REFERENCES internaute (id_internaute)
        ON DELETE CASCADE;

ALTER TABLE description
    add CONSTRAINT fk2_description FOREIGN KEY (id_recette)
    	REFERENCES recette (id_recette)
        ON DELETE CASCADE;

ALTER TABLE commentaire
    add CONSTRAINT fk1_commentaire FOREIGN KEY (id_internaute)
       REFERENCES internaute (id_internaute)
       ON DELETE CASCADE;

ALTER TABLE commentaire
	add CONSTRAINT fk2_commentaire FOREIGN KEY (id_description)
		REFERENCES description (id_description)
        ON DELETE CASCADE;

ALTER TABLE contenir
    add CONSTRAINT fk1_contenir FOREIGN KEY (id_recette)
       REFERENCES recette (id_recette)
       ON DELETE CASCADE;

ALTER TABLE contenir
    add CONSTRAINT fk2_contenir FOREIGN KEY (id_menu)
    	REFERENCES menu (id_menu)
        ON DELETE CASCADE;

ALTER TABLE noter
    add CONSTRAINT fk1_noter FOREIGN KEY (id_internaute)
    	REFERENCES internaute (id_internaute)
        ON DELETE CASCADE;

ALTER TABLE noter
    add CONSTRAINT fk2_noter FOREIGN KEY (id_description)
    	REFERENCES description (id_description)
        ON DELETE CASCADE;

ALTER TABLE comprendre
    add CONSTRAINT fk1_comprendre FOREIGN KEY (id_recette)
       REFERENCES recette (id_recette)
       ON DELETE CASCADE;

ALTER TABLE comprendre
	add CONSTRAINT fk2_comprendre FOREIGN KEY (id_categorie)
		REFERENCES categorie (id_categorie)
        ON DELETE CASCADE;

ALTER TABLE comporter
    add CONSTRAINT fk1_comporter FOREIGN KEY (id_recette)
       REFERENCES recette (id_recette)
       ON DELETE CASCADE;

ALTER TABLE comporter
	add CONSTRAINT fk2_comporter FOREIGN KEY (id_ingredient)
		REFERENCES ingredient (id_ingredient)
        ON DELETE CASCADE;

ALTER TABLE posseder
    add CONSTRAINT fk1_posseder FOREIGN KEY (id_caracteristique)
       REFERENCES caracteristique_nutri (id_caracteristique)
       ON DELETE CASCADE;

ALTER TABLE posseder
	add CONSTRAINT fk2_posseder FOREIGN KEY (id_ingredient)
		REFERENCES ingredient (id_ingredient)
        ON DELETE CASCADE;