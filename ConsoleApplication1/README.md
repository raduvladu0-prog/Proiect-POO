Campionat de Fotbal - Simulatoare
Acest proiect reprezintă o aplicație de tip consolă realizată în C++ care simulează gestionarea unui campionat de fotbal.
 Funcționalități Principale
Generare Echipe: Permite crearea unui număr de echipe cu nume de țări aleatorii.
Sistem de Jucători: Fiecare echipă este formată din 11 jucători generați automat, împărțiți pe roluri specifice: Portar, Fundaș, Mijlocaș și Atacant.
Simulare Meciuri (Tur-Retur): Implementează o logică de joc bazată pe faze, unde statisticile jucătorilor (rating, poziție) influențează rezultatul.
Statistici Jucători: Monitorizează performanțele individuale (goluri, pase de gol, tackle-uri și intervenții ale portarului).
Clasament Real-Time: Calculează punctajul echipelor (3p - victorie, 1p - egal) și afișează clasamentul final.

Jucator (Clasa de bază): Definește atributele comune precum nume, vârstă și rating.

Portar: Extinde Jucator. Include atributul specific penaltyuriAparate, care este incrementat în timpul meciului atunci când portarul reușește să oprească un atac advers.

Fundas: Include logica pentru tackle-uri reușite care pot bloca fazele de atac.

Mijlocas: Gestionează sistemul de pase de gol (asisturi) bazat pe apropierea ratingului față de atacant.

Atacant: Responsabil pentru marcarea golurilor.

Echipa: Gestionează colecția de jucători și conține logica de simulare a meciului.